//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleUserInteractor.h"

#include <iostream>

bool ConsoleUserInteractor::shouldExit() {
    return false;
}

IRequest* ConsoleUserInteractor::readRequest() {
    std::cout
    << "Выберите запрос: " << "\n"
    << "1 - подсчет количества директорий" << "\n";

    int queryNumber;
    std::cin >> queryNumber;

    switch (queryNumber) {
        case 1:
            return readCountDirectoriesRequest();
        default:
            throw std::runtime_error("Неизвестная команда");
    }
}

CountDirectoriesRequest* ConsoleUserInteractor::readCountDirectoriesRequest() {
    std::cout << "Введите путь к директории: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    return new CountDirectoriesRequest(directoryPath, maxDepthLevel);
}
