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
        CQRS/Services/RequestHandler/RequestHandler.cpp
        CQRS/MIddleware/MidlewarePipeline/MiddlewarePipeline.cpp
        CQRS/MIddleware/MidlewarePipeline/MiddlewarePipeline.h
        Infrastructure/Abstractions/ILogger.h
        Infrastructure/Services/ConsoleLogger/ConsoleLogger.cpp
        Infrastructure/Services/ConsoleLogger/ConsoleLogger.h
        Infrastructure/MIddleware/LoggerMiddleware/LoggerMiddleware.cpp
        Infrastructure/MIddleware/LoggerMiddleware/LoggerMiddleware.h
        Infrastructure/MIddleware/ConsoleLoggerMiddleware/ConsoleLoggerMiddleware.h
        CQRS/Services/RequestSender/RequestSender.cpp
        CQRS/Services/RequestSender/RequestSender.h
        Infrastructure/Application/Application.cpp
        Infrastructure/Application/Application.h
        Infrastructure/ApplicationBuilder/ApplicationBuilder.cpp
        Infrastructure/ApplicationBuilder/ApplicationBuilder.h
        Infrastructure/Services/ApplicationRequestRouter/ApplicationRequestRouter.cpp
        Infrastructure/Services/ApplicationRequestRouter/ApplicationRequestRouter.h
)
