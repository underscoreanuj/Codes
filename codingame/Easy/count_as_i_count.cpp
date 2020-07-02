#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int ct = 0;
 
void printPossibilities(int rem_score, int turn) {
    if(turn > 4) return;
    if(turn <= 4 && rem_score == 0) {
        ++ct;
    }
    
    for(int i=1; i<=12; ++i) {
        printPossibilities(rem_score - i, turn + 1);
        if(i > 1)
            printPossibilities(rem_score - i, turn + 1);
    }
    
}

int main()
{
    int n;
    cin >> n; cin.ignore();

    printPossibilities(50 - n, 0);

    cout<<ct<<"\n";
}