// best solution (single pass)

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        int count = 0, idx = 0, prev = 0, next_idx = 0, tmp = 0;

        for (int i = 0; count < nums.size(); ++i)
        {
            idx = i;
            prev = nums[i];
            do
            {
                next_idx = (idx + k) % nums.size();
                tmp = nums[next_idx];
                nums[next_idx] = prev;
                prev = tmp;
                idx = next_idx;
                ++count;
            } while (idx != i);
        }
    }
};

// alternate solution

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// alternate solution

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        std::rotate(nums.rbegin(), nums.rbegin() + (k % nums.size()), nums.rend());
    }
};