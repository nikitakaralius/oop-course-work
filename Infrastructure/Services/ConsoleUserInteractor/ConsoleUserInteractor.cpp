//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleUserInteractor.h"

bool ConsoleUserInteractor::shouldExit() {
    shouldExit_ = !shouldExit_;
    return shouldExit_;
}
