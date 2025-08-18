#include <iostream>
#include "parser.h"
#include <algorithm>
#include <sstream>
command parser::parse(string& s)
{
    string query = s;
    transform(query.begin(), query.end(), query.begin(), ::toupper);
        command cmd;
        
        if(query.substr(0,6)=="CREATE"){
            size_t pos = query.find("TABLE");
           cmd.type=commandType::CREATE; 
           if(pos!=std::string::npos){
                std::stringstream ss(query.substr(pos+5));
                ss>>cmd.tablename;
           }         
        }
        else if(query.substr(0,6)=="INSERT")
        {
            size_t pos = query.find("INTO");
           cmd.type=commandType::INSERT;
           if(pos!=std::string::npos){
                std::stringstream ss(query.substr(pos+4));
                ss>>cmd.tablename;
           } 
        }
        else if(query.substr(0,6)=="SELECT")
        {
            size_t pos = query.find("FROM");
            cmd.type=commandType::SELECT;
            if(pos!=std::string::npos){
                std::stringstream ss(query.substr(pos+4));
                ss>>cmd.tablename;
           } 
        }
        else if(query.substr(0,4)=="EXIT")
        {
            cmd.type=commandType::EXIT;
        }else cmd.type=commandType::UNKNOWN;
        return cmd;
}