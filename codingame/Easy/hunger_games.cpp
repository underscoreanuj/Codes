#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


class Tribute {
public:    
    string name;
    string killer;
    set<string> killed;
  
    Tribute(string name) {
        this->name = name;
        this->killer = "Winner";
    }
    
    void killedTribute(string name) {
        this->killed.insert(name);
    }
    
    void killedBy(string name) {
        this->killer = name;
    }
    
    void print() {
        cout<<"Name: "<<this->name<<"\n";
        cout<<"Killed: ";
        if(this->killed.size() == 0) cout<<"None\n";
        else {
            auto it = this->killed.begin();
            for(it=this->killed.begin(); it!=this->killed.end(); ++it) {
                if(next(it) == this->killed.end()) cout<<(*it)<<"\n";
                else cout<<(*it)<<", ";
            }
        }
        cout<<"Killer: "<<this->killer<<"\n";
    }
    
};


int main()
{
    int tributes;
    cin >> tributes; cin.ignore();
    
    unordered_map<string, Tribute> T;
    
    for (int i = 0; i < tributes; i++) {
        string playerName;
        getline(cin, playerName);
        
        Tribute obj(playerName);
        T.insert({playerName, obj});
    }
    
    int turns;
    cin >> turns; cin.ignore();
    for (int i = 0; i < turns; i++) {
        string info;
        getline(cin, info);
        
        size_t pos = info.find(' ');
        
        string killer_name = info.substr(0, pos);
        auto killer_it = T.find(killer_name);
        
        pos = info.find(' ', pos+1);
        string killed_name_list = info.substr(pos+1, info.length()-pos-1);
        
        size_t cur_pos = 0;
        pos = 0;
        pos = killed_name_list.find(',');
        
        while(pos != string::npos) {
            
            string killed_name = killed_name_list.substr(cur_pos, pos - cur_pos);
            cur_pos = pos+2;
        
            auto killed_it = T.find(killed_name);
            
            killer_it->second.killedTribute(killed_name);
            killed_it->second.killedBy(killer_name);
            
            pos = killed_name_list.find(',', pos+1);
        }
        
        string killed_name = killed_name_list.substr(cur_pos, pos - cur_pos);

        auto killed_it = T.find(killed_name);
        
        killer_it->second.killedTribute(killed_name);
        killed_it->second.killedBy(killer_name);
            
    }
    
    vector<Tribute> op;
    
    for_each(T.begin(), T.end(), [&op](const pair<string, Tribute> &o){
            op.push_back(o.second);
        });
        
    sort(op.begin(), op.end(), [](const Tribute &o1, const Tribute &o2){
            return o1.name < o2.name;
        });
        
    for(int i=0; i<op.size(); ++i) {
        op[i].print();
        if(i+1 < op.size()) cout<<"\n";
    }
    
}