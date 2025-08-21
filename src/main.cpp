#include <bits/stdc++.h>
#include <string>
#include "database.h"
#include "parser.h"

using namespace std;

int main() {
    database db;  
    parser p;     

    while (true) {
        cout << "db> ";

        string s;
        getline(cin, s);

        if (s.empty()) continue;

        command cmd = p.parse(s);   
        db.execute(cmd);           
    }

    return 0;
}
