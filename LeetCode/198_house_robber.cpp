// O(1) solution

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int incl = 0, excl = 0, tmp;
        for (int &n : nums)
        {
            tmp = incl;
            incl = max(incl, n + excl);
            excl = tmp;
        }

        return max(incl, excl);
    }
};

// iterative DP solution

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> tab(nums.size() + 2);
        tab[nums.size()] = tab[nums.size() + 1] = 0;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            tab[i] = max(nums[i] + tab[i + 2], tab[i + 1]);
        }

        return tab[0];
    }
};

// recursive approach with memoization

class Solution
{
public:
    unordered_map<int, int> MEM;

    int robUtil(vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
            return 0;
        if (MEM.count(idx))
            return MEM[idx];

        int including_cur = nums[idx] + robUtil(nums, idx + 2);
        int excluding_cur = robUtil(nums, idx + 1);

        int result = max(including_cur, excluding_cur);

        MEM[idx] = result;

        return result;
    }

    int rob(vector<int> &nums)
    {
        return robUtil(nums, 0);
    }
};
