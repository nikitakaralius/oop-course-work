//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleUserInteractor.h"

#include <iostream>

bool ConsoleUserInteractor::shouldExit() {
    return false;
}

IRequest* ConsoleUserInteractor::readRequest() {
    int a;
    std::cin >> a;
    return new MockRequest();
}
