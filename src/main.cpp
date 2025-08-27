#include <iostream>
#include <exception>
#include <map>

#include "client/config.hpp"
#include "server/config.hpp"
#include "util/cmd_parser.hpp"

server::Config server_config;
client::Config client_config;
util::CmdParser cmd_parser({},{
    {"--mode", "server"}, 
    {"--connections", "512"}, 
    {"--seed", "1337"}});

int main(int argc, char* argv[]){
    std::cout << "TCP-EPOLL!" << std::endl;

    try
    {
        cmd_parser.process_args(argc, argv);

        if(cmd_parser.get_value("--mode") == "server"){
            std::cout << "It's server!" << std::endl;
        }else{
            std::cout << "It's client!" << std::endl;
            std::cout << "Connections -> " << cmd_parser.get_value("--connections") << std::endl;
            std::cout << "Seed -> " << cmd_parser.get_value("--seed") << std::endl;
        }
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}