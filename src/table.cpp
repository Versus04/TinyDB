#include "table.h"
#include <fstream>
#include <sstream>
#include <algorithm>
void Table::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if(!out)return;
    for(size_t  i=0;i<colname.size() ;i++)
    {
        out<<colname[i]<<" "<<coltype[i];
        if (i < colname.size() - 1) out << ", ";
    }
    out<<"\n";
    for(auto& row : rows)
    {
        for(size_t i=0 ; i< row.size();i++){
            out<<row[i];
            if(i<row.size()-1)out<<",";
        }
        out<<"\n";
    }
}
void Table::loadFromFile(const std::string& filename){
    std::ifstream in(filename);
    if(!in)return;
     std::string line;
     if(std::getline(in,line)){
        std::stringstream stream(line);
         std::string coldef;
         while(std::getline(stream,coldef,',')){
            coldef.erase(0, coldef.find_first_not_of(" \t"));
            coldef.erase(coldef.find_last_not_of(" \t") + 1);
            std::stringstream ss(coldef);
            std::string name,type;
            ss>>name>>type;
            colname.push_back(name);
            coltype.push_back(type);
         }
     }
     while(std::getline(in,line)){
        std::stringstream ss(line);
        std::string val;
        std::vector<std::string> row;
         while (std::getline(ss, val, ',')) {
            val.erase(0, val.find_first_not_of(" \t\""));
            val.erase(val.find_last_not_of(" \t\"") + 1);
            row.push_back(val);
        }
        if (!row.empty()) rows.push_back(row);
     }
}