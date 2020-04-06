// better solution (same time & space complexity though)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < nums.size(); ++i)
        {
            // add the new element meanwhile replacing all smaller elements
            while (!window.empty() && nums[i] >= nums[window.back()])
                window.pop_back();
            window.emplace_back(i);
            if (i >= k - 1)
                result.emplace_back(nums[window.front()]);

            // remove all indices outside the next window in left
            while (!window.empty() && window.front() <= i - k + 1)
                window.pop_front();
        }

        return result;
    }
};

// first solution

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> window;

        // process the first k elements
        for (int i = 0; i < k; ++i)
        {
            while (!window.empty() && nums[i] >= nums[window.back()])
                window.pop_back();
            window.emplace_back(i);
        }

        result.emplace_back(nums[window.front()]);

        int win_start = 1;
        for (int win_end = k; win_end < nums.size(); ++win_end)
        {
            // remove all indices outside the window in left
            while (!window.empty() && window.front() < win_start)
                window.pop_front();

            // add the new element at win_end
            while (!window.empty() && nums[win_end] >= nums[window.back()])
                window.pop_back();
            window.emplace_back(win_end);

            result.emplace_back(nums[window.front()]);
            ++win_start;
        }

        return result;
    }
};