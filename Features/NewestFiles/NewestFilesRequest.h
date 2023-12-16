//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef NEWESTFILESREQUEST_H
#define NEWESTFILESREQUEST_H

#include "../Common/FilesRequest.h"

class NewestFilesRequest : public FilesRequest {
public:
    NewestFilesRequest(
        const std::string& directoryPath,
        int maxDepthLevel,
        time_t time_threshold)
        : FilesRequest(directoryPath, maxDepthLevel),
          timeThreshold(time_threshold) { }

    time_t getTimeThreshold() const { return timeThreshold; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Самые новые файлв в "
        << getDirectoryPath() << " "
        << getMaxDepthLevelDesription();

        return ss.str();
    };

private:
    time_t timeThreshold;
};

#endif //NEWESTFILESREQUEST_H
