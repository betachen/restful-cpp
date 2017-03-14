#include <iostream>
#include <string>
#include <restful-cpp/client.hpp>

void my_impl(const http_message* hm){
        auto&& reply = std::string(hm->body.p, hm->body.len);
            std::cout<<reply<<std::endl;
}

int main(int argc, char* argv[])
{
    std::string url{"baidu.com:80"};
    // TODO. Link error for mongoo.h in hidden
    rfcpp::client::MyClient req(url, 3000, my_impl);
    req.get();
    return 0;
}
