#include <iostream>
#include <string>
#include <vector>
enum class commandType{
    CREATE , INSERT , EXIT , SELECT ,UNKNOWN
};
struct command{
    commandType type;
    std::string tablename;
    std::vector<std::string>values;
};
