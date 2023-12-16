#include <iostream>

#include "Infrastructure/ApplicationBuilder/ApplicationBuilder.h"
#include "Infrastructure/MIddleware/ConsoleLoggerMiddleware/ConsoleLoggerMiddleware.h"
#include "Infrastructure/Services/ApplicationRequestRouter/ApplicationRequestRouter.h"


int main() {
    const auto app = ApplicationBuilder::create()
            .withRequestRouter(new ApplicationRequestRouter)
            .build();

    app->use(new ConsoleLoggerMiddleware);
    app->run();

    delete app;
    return 0;
}
