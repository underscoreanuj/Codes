#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int getPosition(string s, int start=0) {
    return s.find(';', start);
}


int main()
{
    int N;
    cin >> N; cin.ignore();
    string XthenCOMMANDS;
    getline(cin, XthenCOMMANDS);
    
    int cur_position = 0;
    int next_position = getPosition(XthenCOMMANDS, cur_position);
    int pos = stol(XthenCOMMANDS.substr(cur_position, next_position));
    
    cur_position = next_position+1;
    next_position = getPosition(XthenCOMMANDS, cur_position);
    string cur_ins = XthenCOMMANDS.substr(cur_position, next_position-cur_position);
    char dir = cur_ins[cur_ins.length()-1];
    int dist = stol(cur_ins.substr(0, cur_ins.length()-1));
    
    for (int i = 0; i < N; i++) {
        string RthenROADPATTERN;
        getline(cin, RthenROADPATTERN);
        
        int t_pos = RthenROADPATTERN.find(';');
        int R = stol(RthenROADPATTERN.substr(0, t_pos));
        string road = RthenROADPATTERN.substr(t_pos+1, RthenROADPATTERN.length()-t_pos-1);
        
        for(int k=0; k<R; ++k) {
            
            if(dist == 0) {
                cur_position = next_position+1;
                next_position = getPosition(XthenCOMMANDS, cur_position);
                string cur_ins = XthenCOMMANDS.substr(cur_position, next_position-cur_position);
                dir = cur_ins[cur_ins.length()-1];
                dist = stol(cur_ins.substr(0, cur_ins.length()-1));
            }
            
            if(dir == 'R') ++pos;
            else if(dir == 'L') --pos;

            for(int r=0; r<road.length(); ++r) {
                
                if(r == pos-1) {
                    cout<<"#";
                    --dist;
                }
                else cout<<road[r];
            }
            cout<<"\n";
        }
        
    }

}