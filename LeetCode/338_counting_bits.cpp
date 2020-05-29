/**
 * 
 * 
 * the idea of recurrence relation is simple:
 *  for a number X : 10011001
 *  result[i >> 1] -> gives the number of ones in X/2 -> number of ones in : 1001100
 *  (i & 1)        -> gives the 1 if the number is odd else 0
 * 
 * */

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result = {0};

        for (int i = 1; i <= num; ++i)
            result.push_back(result[i >> 1] + (i & 1));

        return result;
    }
};