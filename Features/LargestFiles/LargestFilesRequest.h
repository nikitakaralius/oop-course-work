//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESREQUEST_H
#define LARGESTFILESREQUEST_H


#include "../Common/FilesRequest.h"
#include <vector>


class LargestFilesRequest final : public FilesRequest {
public:
    LargestFilesRequest(
        const std::string directoryPath,
        const int maxDepthLevel,
        const long long sizeThreshold)
        : FilesRequest(directoryPath, maxDepthLevel),
          _sizeThreshold(sizeThreshold) { }

    long long sizeThreshold() const { return _sizeThreshold; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Самые болишие файлы в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    };

private:
    long long _sizeThreshold;
};

#endif //LARGESTFILESREQUEST_H
