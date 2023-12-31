//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef CONSOLEUSERINTERACTOR_H
#define CONSOLEUSERINTERACTOR_H

#include "../../../Features/CountDirectories/CountDirectoriesRequest.h"
#include "../../../Features/CountFiles/CountFilesRequest.h"
#include "../../../Features/CountTotalSize/CountTotalSizeRequest.h"
#include "../../../Features/FindDuplicates/FindDuplicatesRequest.h"
#include "../../../Features/LargestFiles/LargestFilesRequest.h"
#include "../../../Features/NewestFiles/NewestFilesRequest.h"
#include "../../Abstractions/IUserInteractor.h"


class NewestFilesResponse;

class ConsoleUserInteractor final : public IUserInteractor {
public:
    bool shouldExit() override;

    IRequest* readRequest() override;

private:
    bool _shouldExit = false;

    CountDirectoriesRequest* readCountDirectoriesRequest();
    CountFilesRequest* readCountFilesRequest();
    CountTotalSizeRequest* readCountTotalSizeRequest();
    LargestFilesRequest* readLargestFilesRequest();
    NewestFilesRequest* readNewestFilesRequest();
    FindDuplicatesRequest* readFindDuplicatesRequest();
};



#endif //CONSOLEUSERINTERACTOR_H
