//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationRequestRouter.h"

#include "../../../Features/CountDirectories/CountDirectoriesRequest.h"
#include "../../../Features/CountDirectories/CountDirectoriesRequestHandler.h"
#include "../../../Features/CountFiles/CountFilesRequest.h"
#include "../../../Features/CountFiles/CountFilesRequestHandler.h"

IRequestHandler* ApplicationRequestRouter::getHandler(IRequest& request) {
    if (dynamic_cast<CountDirectoriesRequest*>(&request))
        return new CountDirectoriesRequestHandler;

    if (dynamic_cast<CountFilesRequest*>(&request))
        return new CountFilesRequestHandler;

    throw std::runtime_error("not yet implemeted");
}
