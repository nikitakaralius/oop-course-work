//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef MIDDLEWAREPIPELINE_H
#define MIDDLEWAREPIPELINE_H

#include <vector>

#include "../../Abstractions/IMiddleware.h"
#include "../../Services/RequestHandler/RequestHandler.h"


class MiddlewarePipeline {
public:
    explicit MiddlewarePipeline(RequestHandler* requestHandler)
        : _requestHandler(requestHandler) { }

    ~MiddlewarePipeline();

    void use(IMiddleware* middleware);

    IResponse* process(IRequest& request);

private:
    std::vector<IMiddleware*> _middlewares;
    RequestHandler* _requestHandler;
};



#endif //MIDDLEWAREPIPELINE_H
