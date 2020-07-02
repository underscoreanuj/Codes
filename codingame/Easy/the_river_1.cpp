#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int getDigitSum(int a) {
    return a ? a%10 + getDigitSum(a/10) : 0;
}

int main()
{
    long long r1;
    cin >> r1; cin.ignore();
    long long r2;
    cin >> r2; cin.ignore();

    while(r1 != r2) {
        if(r1 < r2) r1 += getDigitSum(r1);
        else if(r1 > r2) r2 += getDigitSum(r2);
    }

    cout << r1 << endl;
}