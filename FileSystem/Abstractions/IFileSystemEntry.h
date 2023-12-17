//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef IFILESYSTEMENTRY_H
#define IFILESYSTEMENTRY_H

#include <string>

class IFileSystemEntry {
public:
    virtual ~IFileSystemEntry() = default;

    virtual std::string name() = 0;
    virtual long long size() = 0;
    virtual time_t updatedAt() = 0;

protected:
    template<typename TP>
    std::time_t toTimeT(TP tp) {
        using namespace std::chrono;
        auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
        return system_clock::to_time_t(sctp);
    }
};

#endif //IFILESYSTEMENTRY_H
