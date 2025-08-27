#include <string>

namespace client {
    struct Config {
        std::string addr;
        int connections;
        int seed;
    };
}