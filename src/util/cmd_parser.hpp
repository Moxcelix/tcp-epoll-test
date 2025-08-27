#ifndef CMD_PARSER_HPP
#define CMD_PARSER_HPP

#include <map>
#include <string>
#include <vector>
#include <exception>

namespace util {
    class CmdParser {
    private:
        std::vector<std::string> defined_flags;
        std::map<std::string, std::string> defined_params;

        std::vector<std::string> received_flags;
        std::map<std::string, std::string> received_params;

    public:
        CmdParser(
            std::vector<std::string> defined_flags, 
            std::map<std::string, std::string> defined_params
        );

        void process_args(int argc, char* argv[]);
        bool get_flag(const std::string& flag);
        std::string get_value(const std::string& param);
        bool has_param(const std::string& param);
    };
}

#endif // CMD_PARSER_HPP