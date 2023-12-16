//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "../../CQRS/MIddleware/MidlewarePipeline/MiddlewarePipeline.h"


class Application {
public:
    explicit Application(RequestHandler* requestHandler);

    ~Application();

    void use(IMiddleware* middleware) const;

    void run() const;

private:
    MiddlewarePipeline* middlewarePipeline;
    RequestHandler* requestHandler;
};



#endif //APPLICATION_H
