//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "RequestSender.h"

void RequestSender::send(IRequest& request) {
    this->_requestHandler->handleRequest(request);
}
