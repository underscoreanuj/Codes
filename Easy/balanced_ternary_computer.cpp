#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


string printBalancedTernary(int n)  {
    if(n < 0) {
        string response = printBalancedTernary(-n);
        transform(response.begin(), response.end(), response.begin(), [](char c){
                if(c == 'T') return '1';
                else if(c == '1') return 'T';
                return c;
            });
        return response;
    }
    
    if(n == 0) return "";
    
    if(n%3 == 0) return printBalancedTernary(n/3)+"0";
    else if(n%3 == 1) return printBalancedTernary(n/3)+"1";
    else return printBalancedTernary((n/3)+1)+"T";
}


int main()
{
    int N;
    cin >> N; cin.ignore();

    if(N == 0) {
        cout<<"0\n";
        return 0;
    }

    cout<<printBalancedTernary(N)<<"\n";
}