#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>

enum class commandType {
    CREATE, INSERT, EXIT, SELECT, UNKNOWN
};

struct command {
    commandType type;
    std::string tablename;
    std::vector<std::string> values;
    std::vector<std::string> columns;
    std::vector<std::string> columnTypes;
};

#endif