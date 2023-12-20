//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESREQUEST_H
#define NEWESTFILESREQUEST_H

#include "../Common/FilesRequest.h"
#include <vector>


class NewestFilesRequest final : public FilesRequest {
public:
    NewestFilesRequest(
        const std::string directoryPath,
        const int maxDepthLevel,
        const time_t timeThreshold)
        : FilesRequest(directoryPath, maxDepthLevel),
          _timeThreshold(timeThreshold) { }

    time_t timeThreshold() const { return _timeThreshold; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Поиск самых новых файлов в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    };

private:
    time_t _timeThreshold;
};

#endif //NEWESTFILESREQUEST_H
