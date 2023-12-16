//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "CountFilesRequestHandler.h"

#include "../QueryFiles/QueryFilesRequestHandler.h"

CountFilesResponse* CountFilesRequestHandler::handleRequest(const CountFilesRequest& request) {
    auto queryFilesHandler = QueryFilesRequestHandler();
    auto query = QueryFilesRequest(request.getMaxDepthLevel(), request.getDirectoryPath());
    auto queryFilesResponse = queryFilesHandler.handleRequest(query);
    auto response =  new CountFilesResponse(queryFilesResponse->getFiles().size());
    delete queryFilesResponse;
    return response;
}
