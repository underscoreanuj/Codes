#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

// vector<int> multiply(vector<int>& num1, vector<int>& num2) {
//     // multiplies two vectors as numbers
//     vector<int> res(num1.size()+num2.size(), 0);
//     int prod = 0;

//     for(int i=num1.size()-1; i>=0; --i) {
//         for(int j=num2.size()-1; j>=0; --j) {
//             prod = res[i+j+1] + num1[i]*num2[j];
//             res[i+j+1] = prod%10;
//             res[i+j] += prod/10;
//         }
//     }

//     return res;
// }

// int getPowerDigitSum(int n) {
//     // returns the sum of digits of 2^n
//     if(n == 0) return 1;

//     vector<int> res = {1};
//     vector<int> res2 = {2};

//     while(n) {
//         if(~n&1) {      // n is even
//             res2 = multiply(res2, res2);
//             n >>= 1;
//         }
//         else {
//             res = multiply(res, res2);
//             --n;
//         }
//     }

//     int digitSum = 0;

//     for(auto r : res) {
//         digitSum += r;
//     }

//     return digitSum;
// }

#define MEM_SIZE 10001
int MEM[MEM_SIZE];

void multiplyByTwo(vector<int> &num)
{
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i)
    {
        num[i] *= 2;
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;
    }
    if (carry)
        num.insert(num.begin(), carry);
}

void preCompute()
{
    for (int i = 0; i < MEM_SIZE; ++i)
        MEM[i] = 0;

    MEM[0] = 1;
    MEM[1] = 2;
    vector<int> pows = {2};
    for (int i = 2; i < MEM_SIZE; ++i)
    {
        multiplyByTwo(pows);
        MEM[i] = accumulate(pows.begin(), pows.end(), 0);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0;
    cin >> t;

    preCompute();

    while (t--)
    {
        cin >> n;
        // cout<<getPowerDigitSum(n)<<"\n";     // this gives a TLE on a few cases
        cout << MEM[n] << "\n";
    }

    return 0;
}
