// fast solution (using a double sized array to store -ve indices in an array)

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int result = 0, cur_sum = 0, idx = 0;
        int MEM_SIZE = 2 * nums.size() + 1;
        vector<int> MEM(MEM_SIZE, -2); // to store -ve values
        MEM[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            cur_sum += (nums[i] == 0) ? -1 : 1;
            idx = (MEM_SIZE + cur_sum) % MEM_SIZE;

            if (MEM[idx] != -2)
                result = max(result, i - MEM[idx]);
            else
                MEM[idx] = i;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// my first solution using unordered_map

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int result = 0, cur_sum = 0;
        unordered_map<int, int> MEM = {{0, -1}};

        for (int i = 0; i < nums.size(); ++i)
        {
            cur_sum = (nums[i] == 0) ? cur_sum - 1 : cur_sum + 1;

            if (MEM.count(cur_sum))
                result = max(result, i - MEM[cur_sum]);
            else
                MEM[cur_sum] = i;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();