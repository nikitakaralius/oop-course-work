//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MIDDLEWAREPIPELINE_H
#define MIDDLEWAREPIPELINE_H

#include <vector>

#include "../../Abstractions/IMiddleware.h"
#include "../../Services/RequestHandler/RequestHandler.h"


class MiddlewarePipeline {
private:
    std::vector<IMiddleware*> middlewares;
    RequestHandler* requestHandler;

public:
    explicit MiddlewarePipeline(RequestHandler* request_handler)
        : requestHandler(request_handler) { }

    ~MiddlewarePipeline();

    void use(IMiddleware* middleware);

    IResponse* process(IRequest& request);
};



#endif //MIDDLEWAREPIPELINE_H
