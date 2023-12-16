//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef DATETIME_H
#define DATETIME_H

class   DateTime {
public:
    explicit DateTime(long long ticks) : ticks(ticks) { }

private:
    long long ticks;
};

#endif //DATETIME_H
