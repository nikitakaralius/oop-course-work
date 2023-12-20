//
// Created by Nikita Karalyus on 17/12/2023.
//

#include "ExceptionHandlingMiddleware.h"

#include <filesystem>

#include "../../../Features/Exception/ExceptionResponse.h"
#include "../../../FileSystem/Exceptions/ApplicationException.h"

IResponse* ExceptionHandlingMiddleware::invoke(
    IRequest& request,
    const std::function<IResponse*(IRequest&)> next) {
    try {
        return next(request);
    } catch (ApplicationException& ex) {
        return new ExceptionResponse(ex.message());
    } catch (std::filesystem::filesystem_error& ex) {
        return new ExceptionResponse(ex.what());
    } catch (std::exception& ex) {
        return new ExceptionResponse(ex.what());
    }
}
