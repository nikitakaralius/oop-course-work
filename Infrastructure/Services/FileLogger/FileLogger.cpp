//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FileLogger.h"

#include <fstream>

void FileLogger::log(std::string text) {
    std::ofstream file(filePath, std::ios::app);
    file<< "[LOG]\t"<< text << std::endl;
    file.close();
}
