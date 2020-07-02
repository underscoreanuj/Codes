#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string stringSum(string num1, string num2)
{
    /*
        adds two string numbers
    */
    if (num1.length() < num2.length())
        return stringSum(num2, num1);
    // num1 is always larger or equal in size to num2
    string result(num1.size() + 1, '0');
    int i = num1.size() - 1, sum = 0;

    for (int j = num2.size() - 1; j >= 0; --j)
    {
        sum = (num1[i] - '0') + (num2[j] - '0') + (result[i + 1] - '0');
        result[i + 1] = sum % 10 + '0';
        result[i] += sum / 10;
        --i;
    }

    while (i >= 0)
    {
        sum = (result[i + 1] - '0') + (num1[i] - '0');
        result[i + 1] = sum % 10 + '0';
        result[i] += sum / 10;
        --i;
    }

    return result[0] == '0' ? result.substr(1, result.length() - 1) : result;
}

string addStringNums(vector<string> &nums, int start, int end)
{
    /*
        recursively adds a list of string numbers
    */
    if (start == end)
        return nums[start];
    if (end - start == 1)
        return stringSum(nums[start], nums[end]);

    int mid = start + ((end - start) >> 1);
    string left = addStringNums(nums, start, mid);
    string right = addStringNums(nums, mid + 1, end);

    return stringSum(left, right);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;

    vector<string> nums;
    string num;

    while (n--)
    {
        cin >> num;
        nums.emplace_back(num);
    }

    string sum = addStringNums(nums, 0, nums.size() - 1);
    cout << sum.substr(0, 10);

    return 0;
}
