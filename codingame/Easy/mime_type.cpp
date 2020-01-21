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
 
string tolower(string s) {
    for(int i=0; i<s.length(); ++i) {
        if(s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }
    return s;
}
 
string getExtension(string fname) {
    int i;
    for(i=fname.length()-1; i>=0; --i) {
        if(fname[i] == '.') break;
    }
    if(i < 0) return "?";
    else return tolower(fname.substr(i+1, fname.length()-i-1));
}

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    unordered_map<string, string> tab;
    tab["?"] = "UNKNOWN";
    
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        tab[tolower(EXT)] = MT;
    }
    for (int i = 0; i < Q; i++) {
        string FNAME;
        getline(cin, FNAME); // One file name per line.
        
        string ext = getExtension(FNAME);
        if(tab.find(ext) != tab.end())
            cout<< tab[ext] <<endl;
        else
            cout<< "UNKNOWN" <<endl;
    }

}