#include <iostream>
#include <vector>
#include <unordered_map>
struct Table{
    std::vector<std::string> coltype;
    std::vector<std::string>colname;
    std::vector<std::vector<std::string>> rows;
};
class database{
    private:
    std::unordered_map<std::string,Table> tables;
    public:
    void execute(const command& cmd);
};