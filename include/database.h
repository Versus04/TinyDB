#include <iostream>
#include <vector>
#include "command.h"
#include <unordered_map>
#include "table.h"
class database{
    private:
    std::unordered_map<std::string,Table> tables;
    public:
    void execute(const command& cmd);
    void saveAll(const std::string& folder = "data");
    void loadAll(const std::string& folder = "data");
};