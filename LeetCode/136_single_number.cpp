class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int single_num = 0;
        for (int &n : nums)
            single_num ^= n;

        return single_num;
    }
};