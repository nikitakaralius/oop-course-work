#include <iomanip>
#include <iostream>

#include "Infrastructure/ApplicationBuilder/ApplicationBuilder.h"
#include "Infrastructure/Middleware/ConsoleLoggerMiddleware/ConsoleLoggerMiddleware.h"
#include "Infrastructure/Middleware/FileLoggerMiddleware/FileLoggerMiddleware.h"
#include "Infrastructure/Services/ApplicationRequestRouter/ApplicationRequestRouter.h"
#include "Infrastructure/Services/ConsoleUserInteractor/ConsoleUserInteractor.h"


int main() {
    std::tm tm = {};
    std::stringstream ss("2023-12-16 08:30:00");
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    time_t time = std::mktime(&tm);

    std::cout << std::ctime(&time) << std::endl;

    std::tm tm1 = {};
    std::stringstream ss1("2023-12-17 08:30:00");
    ss1 >> std::get_time(&tm1, "%Y-%m-%d %H:%M:%S");
    time_t time1 = std::mktime(&tm1);

    std::cout << std::ctime(&time1) << std::endl;

    auto lol = time > time1;

    const auto app = ApplicationBuilder::create()
            .addRequestRouter(new ApplicationRequestRouter)
            .addUserInteractor(new ConsoleUserInteractor)
            .build();

    app->use(new ConsoleLoggerMiddleware);
    app->use(new FileLoggerMiddleware);
    app->run();

    delete app;
    return 0;
}
