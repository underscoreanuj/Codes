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

double getWeight(string s, int e) {
    stack<char> ST;
    for(int i=0; i<e; ++i) {
        if(s[i] == '-') continue;
        if(i>0 && s[i-1] == '-' && ST.top() == s[i]) {
            ST.pop();
        }
        else {
            ST.push(s[i]);
        }
    }
    
    return 1.0/(1.0 + ST.size());
}


class MySort{
public:
    bool operator()(const pair<char, double> o1, const pair<char, double> o2) {
        if (o1.second > o2.second) return true;
        else if(o1.second == o2.second) return o1.first < o2.first;
        return false;
    }
};


int main()
{
    string sequence;
    getline(cin, sequence);

    unordered_map<char, double> op;
    op[sequence[0]] = 1;
    
    for(int i=1; i<sequence.length(); ++i) {
        if(sequence[i] == '-') continue;
        if(sequence[i-1] != '-') {
            double tmp = getWeight(sequence, i);
            op[sequence[i]] += tmp;
        }
    }
    
    vector<pair<char, double> > result(op.begin(), op.end());
    
    sort(result.begin(), result.end(), MySort());

    cout << result[0].first << endl;
}