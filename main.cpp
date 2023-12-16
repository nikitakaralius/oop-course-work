#include "Infrastructure/ApplicationBuilder/ApplicationBuilder.h"
#include "Infrastructure/Middleware/ConsoleLoggerMiddleware/ConsoleLoggerMiddleware.h"
#include "Infrastructure/Middleware/FileLoggerMiddleware/FileLoggerMiddleware.h"
#include "Infrastructure/Services/ApplicationRequestRouter/ApplicationRequestRouter.h"
#include "Infrastructure/Services/ConsoleUserInteractor/ConsoleUserInteractor.h"


int main() {
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
