cmake_minimum_required(VERSION 3.27)
project(FileWizard)

set(CMAKE_CXX_STANDARD 23)

add_executable(FileWizard main.cpp
        CQRS/Abstractions/IStringFormattable.h
        CQRS/Alias.h
        CQRS/Abstractions/IRequest.h
        CQRS/Abstractions/IRequest.h
        CQRS/Abstractions/IGenericRequestHandler.h
        CQRS/Abstractions/IMiddleware.h
        CQRS/Abstractions/IResponse.h
        CQRS/Abstractions/IRequestSender.h
        CQRS/Abstractions/IRequestRouter.h
        CQRS/Services/RequestHandler/RequestHandler.cpp
        CQRS/Services/RequestHandler/RequestHandler.h
)
