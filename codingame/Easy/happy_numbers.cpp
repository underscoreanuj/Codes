#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

unordered_set<string> ST;
unordered_set<string> TR;
 
bool isHappy(string s) {
    
    if(ST.find(s) != ST.end()) return true;
    
    if(TR.find(s) != ST.end()) return false;
    
    TR.insert(s);
    
    size_t num = 0;
    for(int i=0; i<s.length(); ++i) num += powl((s[i] - '0'), 2);
    
    
    if(num == 1) {
        ST.insert(s);
        return true;
    }
    
    else{
        if(isHappy(to_string(num))) {
            ST.insert(s);
            return true;
        }
        else {
            TR.insert(s);
            return false;
        }

    }
}

int main()
{
    int N;
    string happy = ":)";
    string unhappy = ":(";
    
    cin >> N; cin.ignore();

    for (int i = 0; i < N; i++) {
        string x;
        getline(cin, x);
        
        if(isHappy(x)) cout<<x<<" "<<happy<<"\n";
        else cout<<x<<" "<<unhappy<<"\n";
    }

}