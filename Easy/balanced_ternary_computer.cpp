#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    
    if(n == 0) {
        cout<<"0\n";
        return 0;
    }
    
    bool neg = n < 0;

    stack<char> resp;
    char tmp;
    int rem = 0;
    bool prev = false;
    
    n = abs(n);
    
    while(n) {
        rem = n%3;
        n /= 3;

        if(rem == 2) {
            if(prev) {
                resp.pop();
                resp.push('0');
                resp.push('1');  
            }
            else {
                resp.push('T');
                resp.push('1');                
            }
            prev = true;
        }
        else {
            if(prev) {
                resp.pop();
                if(rem == 0) {
                    resp.push(1);
                    prev = false;
                }
                else {
                    resp.push('T');
                    resp.push('1');   
                    prev = true;
                }
            }
            else {
                resp.push(rem+'0');
                prev = false;
            }
        }
    }
    
    if(neg) {
        while(!resp.empty()) {
            if(resp.top() == '1') cout<<'T';
            else if(resp.top() == 'T') cout<<'1';
            else cout<<resp.top();
            resp.pop();
        }
        return 0;
    }
    
    while(!resp.empty()) {
        cout<<resp.top();
        resp.pop();
    }
    
    cout<<"\n";
}