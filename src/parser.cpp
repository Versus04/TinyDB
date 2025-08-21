#include <iostream>
#include "parser.h"
#include <algorithm>
#include <sstream>
command parser::parse(string& s)
{
    
    string query = s;
    std::string queryUpper = query;
transform(queryUpper.begin(), queryUpper.end(), queryUpper.begin(), ::toupper);
        command cmd;
        
        if(queryUpper.substr(0,6)=="CREATE"){
            size_t pos = queryUpper.find("TABLE");
           cmd.type=commandType::CREATE; 
           if(pos!=std::string::npos){
                std::stringstream ss(query.substr(pos+5));
                ss>>cmd.tablename;
                size_t start  = query.find('(');
                size_t end = query.find(')');
                if(start!=std::string::npos && end!=std::string::npos && end>start)
                {
                    std::string schemastr  = query.substr(start+1,end-start-1);
                    std::stringstream schemastream(schemastr);
                    std::string coldef;
                    while (std::getline(schemastream,coldef,','))
                    {
                        
                            coldef.erase(0, coldef.find_first_not_of(" \t"));
                            coldef.erase(coldef.find_last_not_of(" \t") + 1);
                            std::stringstream colstream(coldef);
                            std::string colname,coltype;
                            colstream>>colname>>coltype;
                            if(!colname.empty() && !coltype.empty())
                            {
                                cmd.columnTypes.push_back(coltype);
                                cmd.columns.push_back(colname);
                            }   
                    }
                    
                }
              
            }         
        }else if(queryUpper.substr(0,6)=="INSERT")
{
    cmd.type = commandType::INSERT;
    size_t pos = queryUpper.find("INTO");
    if(pos!=std::string::npos){
        std::stringstream ss(query.substr(pos+4)); 
        ss >> cmd.tablename;

        size_t valpos = queryUpper.find("VALUES");
        if(valpos!=std::string::npos){
            size_t start = query.find('(', valpos);
            size_t end   = query.find(')', valpos);
            if(start!=std::string::npos && end!=std::string::npos && end>start )
            {
                std::string valuestr = query.substr(start+1 , end-start-1);
                std::string item;
                std::stringstream valstream(valuestr);
                while(std::getline(valstream,item,',')){
                    item.erase(0, item.find_first_not_of(" \t\""));
                    item.erase(item.find_last_not_of(" \t\"")+1);
                    
                    if (!item.empty()) {
                        cmd.values.push_back(item);
                    }
                }
            }
        }
    }
}
else if(queryUpper.substr(0,6)=="SELECT")
{
    cmd.type = commandType::SELECT;
    size_t pos = queryUpper.find("FROM");
    if(pos!=std::string::npos){
        std::string colpart = query.substr(7,pos-7);
        std::stringstream colStream(colpart);
        std::string col;
        while (std::getline(colStream,col,','))
        {
            col.erase(0,col.find_first_not_of(" \t"));
            col.erase(col.find_last_not_of(" \t")+1);
            if (col=="*")
            {
                cmd.columns.push_back("*");
            }else{
                cmd.columns.push_back(col);
            }
            
        }
        std::stringstream ss(query.substr(pos + 4));
        ss >> cmd.tablename;
        
    }
}

        else if(queryUpper.substr(0,4)=="EXIT")
        {
            cmd.type=commandType::EXIT;
        }else cmd.type=commandType::UNKNOWN;
        return cmd;
}