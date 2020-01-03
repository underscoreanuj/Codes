#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    
    int n_chars = W/3 + 1;
    unordered_map<char, char> Hash;

    string top, top_c, bot;
    string *legs = new string[H-2];
    
    for (int i = 0; i < H; i++) {
        if(i == 0) {
            getline(cin, top);
        }
        else if(i == H-1) {
            getline(cin, bot);
        }
        else {
            getline(cin, legs[i-1]);
        }
    }
    
    for(int i=0; i<W; i+=3) {
        Hash[top[i]] = bot[i];
    }
    
    top_c = top;
    
    
    for (int i = 0; i < H-2; i++) {
        int ind = 0;
        
        ind = legs[i].find("--", ind);
        while(ind != string::npos) {
            
            char tmp = Hash[top_c[ind-1]];
            Hash[top_c[ind-1]] = Hash[top_c[ind+2]];
            Hash[top_c[ind+2]] = tmp;
            
            swap(top_c[ind-1], top_c[ind+2]);
            
            ind = legs[i].find("--", ind+1);
            
        }
    }
    
    for(int i=0; i<W; i+=3) {
        cout<<top[i]<<Hash[top[i]]<<"\n";
    }

}