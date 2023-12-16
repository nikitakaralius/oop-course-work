//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "CountFilesRequestHandler.h"

CountFilesResponse* CountFilesRequestHandler::handleRequest(const CountFilesRequest& request) {
    auto files = getFiles(request);
    auto response =  new CountFilesResponse(files.size());
    return response;
}
