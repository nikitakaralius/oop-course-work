//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include "../../Abstractions/IRequestSender.h"
#include "../RequestHandler/RequestHandler.h"


class RequestSender final : public IRequestSender {
public:
    explicit RequestSender(RequestHandler* request_handler)
        : _requestHandler(request_handler) { }

    void send(IRequest& request) override;

private:
    RequestHandler* _requestHandler;
};



#endif //REQUESTSENDER_H
