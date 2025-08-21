#include <bits/stdc++.h>
#include <string>
#include "database.h"
#include "parser.h"

using namespace std;
int main() {
    //Database db;
    database db;
    parser p;
    while (true)
    {
    cout<<"db>";

    string s;
    getline(cin, s);
    command cmd = p.parse(s);
    cout<<cmd.values.size()<<endl;
        
}
    
    return 0;
}
