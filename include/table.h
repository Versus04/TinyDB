#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

struct Table{
    std::vector<std::string> coltype;
    std::vector<std::string> colname;
    std::vector<std::vector<std::string>> rows;
    
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif 