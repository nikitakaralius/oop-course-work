//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "ConsoleUserInteractor.h"

#include <iomanip>
#include <iostream>

#include "../../../Features/Exit/ExitRequest.h"

bool ConsoleUserInteractor::shouldExit() {
    return _shouldExit;
}

IRequest* ConsoleUserInteractor::readRequest() {
    std::cout
    << "Выберите запрос: " << "\n"
    << "1 - подсчет количества директорий" << "\n"
    << "2 - подсчет количества файлов" << "\n"
    << "3 - подсчет суммарного размера файлов" << "\n"
    << "4 - нахождение самых больших файлов" << "\n"
    << "5 - нахождение самых новых файлов" << "\n"
    << "6 - нахождение дубликатов файлов" << "\n"
    << "e - выход" << "\n";

    char query;
    std::cin >> query;

    switch (query) {
        case '1':
            return readCountDirectoriesRequest();
        case '2':
            return readCountFilesRequest();
        case '3':
            return readCountTotalSizeRequest();
        case '4':
            return readLargestFilesRequest();
        case '5':
            return readNewestFilesRequest();
        case '6':
            return readFindDuplicatesRequest();
        case 'e':
            _shouldExit = true;
            return new ExitRequest();
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

NewestFilesRequest* ConsoleUserInteractor::readNewestFilesRequest() {
    std::cout << "Введите путь к директории: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    std::cout << "Введите минимальный дату и время" << std::endl;
    std::cout << "Формат - 2023-12-16 12:30:45" << std::endl;
    std::string dateTime;
    std::cin >> dateTime;

    time_t timeThreshold;

    try {
        std::tm tm = {};
        std::stringstream ss(dateTime);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        timeThreshold = std::mktime(&tm);
    } catch (std::exception&) {
        throw std::runtime_error("Неверный формат времени");
    }

    return new NewestFilesRequest(directoryPath, maxDepthLevel, timeThreshold);
}

FindDuplicatesRequest* ConsoleUserInteractor::readFindDuplicatesRequest() {
    std::cout << "Введите путь к файлу, дубликат которого будем искать: " << std::endl;
    std::string filePath;
    std::cin >> filePath;

    std::cout << "Введите путь к директории, где буем искать дубликат: " << std::endl;
    std::string directoryPath;
    std::cin >> directoryPath;

    std::cout << "Введите желаемую глубину обхода (-1 для максимальной):" << std::endl;
    int maxDepthLevel;
    std::cin >> maxDepthLevel;

    maxDepthLevel = maxDepthLevel == -1 ? INT_MAX : maxDepthLevel;

    if (maxDepthLevel <= 0)
        throw std::runtime_error("Глубина обхода должна быть либо больше 1, либо -1 для максимальной");

    return new FindDuplicatesRequest(directoryPath, maxDepthLevel, filePath);
}
