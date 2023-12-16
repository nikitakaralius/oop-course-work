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
    << "1 - подсчет количества директорий" << "\n"
    << "2 - подсчет количества файлов" << "\n"
    << "3 - подсчет суммарного размера файлов" << "\n"
    << "4 - нахождение самых больших файлов" << "\n";

    int queryNumber;
    std::cin >> queryNumber;

    switch (queryNumber) {
        case 1:
            return readCountDirectoriesRequest();
        case 2:
            return readCountFilesRequest();
        case 3:
            return readCountTotalSizeRequest();
        case 4:
            return readLargestFilesRequest();
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

CountFilesRequest* ConsoleUserInteractor::readCountFilesRequest() {
    std::cout << "Введите путь к директории: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    return new CountFilesRequest(directoryPath, maxDepthLevel);
}

CountTotalSizeRequest* ConsoleUserInteractor::readCountTotalSizeRequest() {
    std::cout << "Введите путь к директории: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    return new CountTotalSizeRequest(directoryPath, maxDepthLevel);
}

LargestFilesRequest* ConsoleUserInteractor::readLargestFilesRequest() {
    std::cout << "Введите путь к директории: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    std::cout << "Введите минимальный ограничение на размер файла" << std::endl;
    long long sizeThreshold;
    std::cin >> sizeThreshold;

    return new LargestFilesRequest(directoryPath, maxDepthLevel, sizeThreshold);
}
