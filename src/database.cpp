#include <iostream>
#include "command.h"
#include "table.h"
#include "database.h"
#include <unordered_map>
#include <algorithm>
#include <filesystem>
namespace fs = std::filesystem;

void database::execute( const command& cmd)
{
    if(cmd.type==commandType::CREATE)
    {
        if(tables.find(cmd.tablename)!=tables.end())
        {
            std::cout<<"Error: Table "<<cmd.tablename<<" already exists.\n";
            return ;
        }
        Table t;
        t.colname=cmd.columns;
        t.coltype=cmd.columnTypes;
        tables[cmd.tablename]=t;
        std::cout<<"Table "<<cmd.tablename<<" created \n";
    }
    else if(cmd.type==commandType::INSERT){
        if(tables.find(cmd.tablename)==tables.end())
        {
            std::cout<<"Error Table "<<cmd.tablename<<" doesn't exist\n";
            return ;
        }
        Table& t = tables[cmd.tablename];
        if(cmd.values.size()!=t.colname.size()){
            std::cout << "Error: Column count mismatch.\n";
            return;
        }   
        t.rows.push_back(cmd.values);
        std::cout << "Inserted 1 row into " << cmd.tablename << ".\n";
    }
    else if(cmd.type==commandType::SELECT){
        if(tables.find(cmd.tablename)==tables.end()){
            std::cout << "Error: Table " << cmd.tablename << " does not exist.\n";
            return;
        }
        Table& t = tables[cmd.tablename];
        if(cmd.columns.size()==1 && cmd.columns[0]=="*"){
            for (auto& col : t.colname) {
                std::cout << col << "\t";
            }
             std::cout << "\n";
             for(auto& row : t.rows){
                for(auto& val : row){
                    std::cout<<val<<"\t";
                }
                std::cout<<"\n";
             }
        }
        else{
            std::vector<int>indices;
            for(auto& colName  : cmd.columns){
                auto it = std::find(t.colname.begin(), t.colname.end(), colName);
                if(it!=t.colname.end()){
                    indices.push_back(it-t.colname.begin());
                }else{
                    std::cout << "Error: Column " << colName << " not found.\n";
                    return;
                }
            }
            for(auto& colname : cmd.columns){
            std::cout<<colname<<"\t";
                }
                std::cout<<"\n";
                for(auto& rows: t.rows ){
                    for(int idx: indices){
                        std::cout<<rows[idx]<<"\t";
                    }
                    std::cout<<"\n";
                }
        }
       

        } else if(cmd.type==commandType::EXIT){
            saveAll();
            std::cout << "Exiting database...\n";
        exit(0);
        
    }
     else {
        std::cout << "Unknown command.\n";
    }
}
void database::saveAll(const std::string& folder) {
    fs::create_directories(folder);
    for (auto& [name, table] : tables) {
        std::string filename = folder + "/" + name + ".db";
        table.saveToFile(filename);
        std::cout << "Saved table " << name << " -> " << filename << "\n";
    }
}
void database::loadAll(const std::string& folder) {
    if (!fs::exists(folder)) return;

    for (auto& entry : fs::directory_iterator(folder)) {
        if (entry.path().extension() == ".db") {
            std::string tablename = entry.path().stem().string();
            Table t;
            t.loadFromFile(entry.path().string());
            tables[tablename] = t;
            std::cout << "Loaded table " << tablename 
                      << " from " << entry.path().string() << "\n";
        }
    }
}