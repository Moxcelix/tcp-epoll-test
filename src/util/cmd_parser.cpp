#include "cmd_parser.hpp"
#include <algorithm>
#include <stdexcept>

namespace util {
    CmdParser::CmdParser(
        std::vector<std::string> defined_flags, 
        std::map<std::string, std::string> defined_params
    ) {
        this->defined_flags = defined_flags;
        this->defined_params = defined_params;
    }

    void CmdParser::process_args(int argc, char* argv[]) {  
        for(int i = 1; i < argc; i++) {
            const auto arg = static_cast<std::string>(argv[i]);
            
            if(std::find(defined_flags.begin(), defined_flags.end(), arg) != defined_flags.end()) {
                received_flags.push_back(arg);
                continue;
            }
            
            if(defined_params.find(arg) != defined_params.end()) {
                if(i + 1 >= argc) {
                    throw std::runtime_error("Missing value for parameter: " + arg);
                }
                const auto value = static_cast<std::string>(argv[++i]);
                received_params[arg] = value;
                continue;
            }
            
            throw std::runtime_error("Symbol '" + arg + "' is not allowed.");
        }
    }

    bool CmdParser::get_flag(const std::string& flag) {
        return std::find(received_flags.begin(), received_flags.end(), flag) != received_flags.end();
    }

    std::string CmdParser::get_value(const std::string& param) {
        if(received_params.find(param) != received_params.end()) {
            return received_params.at(param);
        }
        if(defined_params.find(param) != defined_params.end()) {
            return defined_params.at(param);
        }
        throw std::runtime_error("Parameter not found: " + param);
    }

    bool CmdParser::has_param(const std::string& param) {
        return received_params.find(param) != received_params.end();
    }
}