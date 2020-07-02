// O(nlogn) solution  with sorting

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>()); // sort in non-increasing order

        vector<int> result;
        int cur_sum = 0;

        for (int &n : nums)
        {
            cur_sum += n;
            result.push_back(n);
            if (cur_sum > sum - cur_sum)
                break;
        }

        return result;
    }
};

// O(nlogn) solution  with priority queue

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        priority_queue<int> PQ(nums.begin(), nums.end());
        vector<int> result;
        int cur_sum = 0;

        while (cur_sum <= sum - cur_sum)
        {
            cur_sum += PQ.top();
            result.push_back(PQ.top());
            PQ.pop();
        }

        return result;
    }
};