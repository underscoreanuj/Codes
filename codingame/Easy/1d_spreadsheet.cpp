#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int *res;
string **operations;

int performOperation(string* );

int getArgument(string s) {
    if(s == "_") return 0;
    if(s[0] == '$') {
        int ref = stoi(s.substr(1, s.length()-1));

        if(res[ref] == -999)
            res[ref] = performOperation(operations[ref]);
            
        return res[ref];
    }
    return stoi(s);
}

int performOperation(string *op) {
    int ret = 0, arg_1, arg_2;
    arg_1 = getArgument(op[1]);
    arg_2 = getArgument(op[2]);

    if(op[0] == "VALUE") {
        ret = arg_1;
    }
    else if(op[0] == "ADD") {
        ret = arg_1 + arg_2;
    }
    else if(op[0] == "SUB") {
        ret = arg_1 - arg_2;
    }

    else if(op[0] == "MULT") {
        ret = arg_1 * arg_2;
    }
    
    return ret;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    res = new int[N];
    operations = new string*[N];
    
    for (int i = 0; i < N; i++) {
        operations[i] = new string[3];
        res[i] = -999;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2]; cin.ignore();
    }
    
    for (int i = 0; i < N; i++) {
        res[i] = performOperation(operations[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << endl;
    }
}