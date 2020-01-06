#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    string sequence;
    getline(cin, sequence);

    unordered_map<char, double> res;
    int depth = 0;
    
    for(int i=0; i<sequence.length(); ++i) {
        if(sequence[i] == '-') {
            res[sequence[++i]] += 1.0/(depth--);
        }
        else {
            ++depth;
        }
    }
    
    auto it = *max_element(res.begin(), res.end(), [](const pair<char, double> &x, const pair<char, double> &y){
            return x.second < y.second;        
        });
    
    cout<<it.first<<"\n";
    
}