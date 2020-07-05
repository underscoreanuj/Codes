/**
 * 
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Two Sigma.
 * Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function rand7() that returns an integer from 1 to 7 (inclusive).
 * 
 * 
 * ref: https://leetcode.com/problems/implement-rand10-using-rand7/
 * 
 * complementary of problem 71
 * 
 */

// The rand5() API is already defined for you.
// int rand5();
// @return a random integer in the range 1 to 5

class Solution
{
public:
    int rand7()
    {
        int result = 0;
        while (true)
        {
            result = (rand5() - 1) * 5 + rand5()(); // generates a number in range of 1-25
            if (result <= 21)
                return (result - 1) % 7 + 1;
        }
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();