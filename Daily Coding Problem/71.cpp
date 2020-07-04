/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Two Sigma.
 * Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability, implement a function rand5() that returns an integer from 1 to 5 (inclusive).
 * 
 * 
 * ref: https://leetcode.com/problems/implement-rand10-using-rand7/discuss/395824/Easily-implement-rand5()-and-rand6()-then-rand10()-is-straightforward
 * 
 */

// assuming rand7() is already availeble

class Solution
{
public:
    int rand5()
    {
        val = rand7();
        while (val > 5)
            val = rand7();

        return val;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
