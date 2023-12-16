//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IREQUESTHANDLER_H
#define IREQUESTHANDLER_H

template<class TRequest, class TResponse>
class IRequestHandler {
public:
    virtual ~IRequestHandler() = default;

    virtual TResponse* handle(const TRequest& request) = 0;
};

#endif //IREQUESTHANDLER_H
