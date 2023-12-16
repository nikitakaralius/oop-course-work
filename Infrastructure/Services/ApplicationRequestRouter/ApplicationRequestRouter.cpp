//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ApplicationRequestRouter.h"

#include "../../../Features/CountDirectories/CountDirectoriesRequest.h"
#include "../../../Features/CountDirectories/CountDirectoriesRequestHandler.h"
#include "../../../Features/CountFiles/CountFilesRequest.h"
#include "../../../Features/CountFiles/CountFilesRequestHandler.h"
#include "../../../Features/CountTotalSize/CountTotalSizeRequest.h"
#include "../../../Features/CountTotalSize/CountTotalSizeRequestHandler.h"
#include "../../../Features/Exit/ExitRequest.h"
#include "../../../Features/Exit/ExitRequestHandler.h"
#include "../../../Features/FindDuplicates/FindDuplicatesRequest.h"
#include "../../../Features/FindDuplicates/FindDuplicatesRequestHandler.h"
#include "../../../Features/LargestFiles/LargestFilesRequest.h"
#include "../../../Features/LargestFiles/LargestFilesRequestHandler.h"
#include "../../../Features/NewestFiles/NewestFilesRequest.h"
#include "../../../Features/NewestFiles/NewestFilesRequestHandler.h"

IRequestHandler* ApplicationRequestRouter::getHandler(IRequest& request) {
    if (dynamic_cast<CountDirectoriesRequest*>(&request))
        return new CountDirectoriesRequestHandler;

    if (dynamic_cast<CountFilesRequest*>(&request))
        return new CountFilesRequestHandler;

    if (dynamic_cast<CountTotalSizeRequest*>(&request))
        return new CountTotalSizeRequestHandler;

    if (dynamic_cast<LargestFilesRequest*>(&request))
        return new LargestFilesRequestHandler;

    if (dynamic_cast<NewestFilesRequest*>(&request))
        return new NewestFilesRequestHandler;

    if (dynamic_cast<FindDuplicatesRequest*>(&request))
        return new FindDuplicatesRequestHandler;

    if (dynamic_cast<ExitRequest*>(&request))
        return new ExitRequestHandler;

    throw std::runtime_error("not yet implemeted");
}
