#include <iostream>
#include <string>
#include <restful-cpp/server.hpp>

using namespace rfcpp;
using namespace rfcpp::server;

int main(int argc, char* argv[])
{
    //TODO.
    MyServer rest_server("webroot");
    // bind
    auto& conn = rest_server.bind("0.0.0.0:8100");
    for (;;)
        rest_server.poll(1000);
    return 0;
}
