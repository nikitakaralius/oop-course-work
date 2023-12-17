//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef LARGESTFILESREQUEST_H
#define LARGESTFILESREQUEST_H


#include "../Common/FilesRequest.h"

class LargestFilesRequest final : public FilesRequest {
public:
    LargestFilesRequest(
        const std::string&directoryPath,
        int maxDepthLevel,
        long long sizeThreshold)
        : FilesRequest(directoryPath, maxDepthLevel),
          sizeThreshold(sizeThreshold) { }

    long long getSizeThreshold() const { return sizeThreshold; }

    std::string toString() override {
        std::stringstream ss;

        ss
        << "Самые болишие файлы в "
        << directoryPath() << " "
        << maxDepthLevelDesription();

        return ss.str();
    };

private:
    long long sizeThreshold;
};

#endif //LARGESTFILESREQUEST_H
