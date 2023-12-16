#include <iostream>

#include "CQRS/Services/DefaultRequestRouter/DefaultRequestRouter.h"
#include "CQRS/Services/MockRequestHandler/MockRequestHandler.h"

int main() {
    DefaultRequestRouter router;

    auto request = MockRequest();
    auto handler = router.getHandler(request);
    auto response = handler->handle(request);

    std::cout << response->toString() << std::endl;

    delete handler;
    delete response;

    return 0;
}
