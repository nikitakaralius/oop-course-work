//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef CONSOLEUSERINTERACTOR_H
#define CONSOLEUSERINTERACTOR_H

#include "../../../Features/CountDirectories/CountDirectoriesRequest.h"
#include "../../Abstractions/IUserInteractor.h"


class ConsoleUserInteractor : public IUserInteractor {
public:
    bool shouldExit() override;

    IRequest* readRequest() override;

private:
    bool shouldExit_ = false;

    CountDirectoriesRequest* readCountDirectoriesRequest();
};



#endif //CONSOLEUSERINTERACTOR_H
