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

int getRotorIdx(char c) {
    return c - 'A';
}

string applyCaesarShift(string m, int s) {
    int ct = 0;
    for(int i=0; i<m.length(); ++i) {
        m[i] = ((m[i] - 'A' + s + ct)%26 + 'A');
        ++ct;
    }
    
    return m;
}

string unapplyCaesarShift(string m, int s) {
    int ct = 0;
    int shift_adj = 26;
    
    while(shift_adj < (s + m.length())) shift_adj += shift_adj;
    
    for(int i=0; i<m.length(); ++i) {
        m[i] = ((m[i] - 'A' - s - ct + shift_adj)%26 + 'A');
        ++ct;
    }
    
    return m;
}

int main()
{
    string Operation;
    getline(cin, Operation);
    int pseudoRandomNumber;
    cin >> pseudoRandomNumber; cin.ignore();
    
    string rotors[3];
    
    for (int i = 0; i < 3; i++) {
        getline(cin, rotors[i]);
    }
    
    string message;
    getline(cin, message);
    
    
    if(Operation == "ENCODE") {
        
        string im = applyCaesarShift(message, pseudoRandomNumber);
        for(int i=0; i<3; ++i) {
            for(int j=0; j<im.length(); ++j) {
                im[j] = rotors[i][getRotorIdx(im[j])];
            }
        }
        cout << im << endl;
    }
    else {
        unordered_map<char, char> rotor_map[3];
    
        for (int i = 0; i < 3; i++) {
            for(int j=0; j<26; ++j) {
                rotor_map[i][rotors[i][j]] = j + 'A';
            }
        }
        
        for(int i=2; i>=0; --i) {
            for(int j=0; j<message.length(); ++j) {
                message[j] = rotor_map[i][message[j]];
            }
        }
        
        string im = unapplyCaesarShift(message, pseudoRandomNumber);
        
        cout << im << endl;
        
    }

}