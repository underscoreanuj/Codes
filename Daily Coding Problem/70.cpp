/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Microsoft.
 * A number is considered perfect if its digits sum up to exactly 10.
 * Given a positive integer n, return the n-th perfect number.
 * For example, given 1, you should return 19. Given 2, you should return 28.
 * 
 * 
 * Online Judge: https://codezen.codingninjas.com/practice/130452/4641/interview-shuriken-21:-n-th-prefect-number 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{

    // Write your code here
    int n = 0;
    cin >> n;

    int count = 0, result = 19;

    while (true)
    {
        if (getSum(result) == 10)
        {
            ++count;
        }
        if (count == n)
            break;
        result += 9;
    }

    cout << result;
}