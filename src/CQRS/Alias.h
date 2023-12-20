//
// Created by Nikita Karalyus on 16/12/2023.
//

#ifndef ALIAS_H
#define ALIAS_H

#include <functional>

#define RequestDelegate std::function<IResponse*(IRequest&)>

#endif //ALIAS_H
