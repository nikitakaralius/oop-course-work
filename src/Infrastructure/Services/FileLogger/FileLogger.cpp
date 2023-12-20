//
// Created by Nikita Karalyus on 16/12/2023.
//

#include "FileLogger.h"

#include <fstream>

void FileLogger::log(const std::string text) {
    std::ofstream file(_filePath, std::ios::app);
    file<< "[LOG]\t"<< text << std::endl;
    file.close();
}
