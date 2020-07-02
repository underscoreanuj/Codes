#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool isOpening(char c) {
    if(c == '[' || c == '(' || c == '{') return true;
    return false;
}

bool isClosing(char c) {
    if(c == ']' || c == ')' || c == '}') return true;
    return false;
}

char getPair(char c) {
    if(c == ']') return '[';
    if(c == ')') return '(';
    if(c == '}') return '{';
}

int main()
{
    string p;
    cin >> p; cin.ignore();
    
    stack<char> S;
    bool flag = true;
    
    for(int i=0; i<p.length(); ++i) {
        if(isOpening(p[i])) {
            S.push(p[i]);
        }
        else if(isClosing(p[i])) {
            if(S.empty() || S.top() != getPair(p[i])) {
                flag = false;
                break;
            }
            else S.pop();
        }
    }
    
    if(flag) flag = S.empty();

    if(flag) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}