//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef CONSOLEUSERINTERACTOR_H
#define CONSOLEUSERINTERACTOR_H

#include "../../Abstractions/IUserInteractor.h"


class ConsoleUserInteractor : public IUserInteractor {
public:
    bool shouldExit() override;

private:
    bool shouldExit_ = false;
};



#endif //CONSOLEUSERINTERACTOR_H
