#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
string getBinaryString(int x) {
    string ret;
    while(x) {
        ret += x%2 + '0';
        x /= 2;
    }
    int n = ret.length();
    
    for(int i=0; i<n/2; ++i) {
        char t = ret[i];
        ret[i] = ret[n-i-1];
        ret[n-i-1] = t;
    }
    if(n < 7) {
        int ct = 7-n;
        while(ct--) ret = "0" + ret;
    }
    return ret.substr(0, 7);
}

void printCN(string s) {
    int ct = 0;
    string op;
    int i = 0;
    while(i<s.length()) {
        ct = 0;
        if(s[i] == '1') {
            op += "0 ";
            while(i < s.length() && s[i] == '1') { ++ct; ++i;}
            while(ct--) op += "0";
        }
        else {
            op += "00 ";
            while(i < s.length() && s[i] == '0') { ++ct; ++i;}
            while(ct--) op += "0";
        }
        op += " ";
    }
    cout<<op.substr(0, op.length()-1);
}

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    string op;
    for(int i=0; i<MESSAGE.length(); ++i) {
        op += getBinaryString(MESSAGE[i]);
    }
    
    
    cerr<<op<<"\n";
    printCN(op);

    cout << endl;
}