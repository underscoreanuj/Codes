// left-max, right-max based solution

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        int n = height.size(), result = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; ++i)
            leftMax[i] = max(height[i], leftMax[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(height[i], rightMax[i + 1]);
        for (int i = 0; i < n; ++i)
            result += max(min(leftMax[i], rightMax[i]) - height[i], 0);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// stack based solution (not as fast than the one above)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), result = 0, cur = 0, len = 0;
        stack<int> S;

        for (int i = 0; i < n; ++i)
        {
            while (S.size() && height[i] > height[S.top()])
            {
                cur = S.top();
                S.pop();
                if (S.size() == 0)
                    break;
                len = i - S.top() - 1;
                result += max(min(height[i], height[S.top()]) - height[cur], 0) * len;
            }
            S.push(i);
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

// constant extra space solution

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), result = 0;
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;

        while (left < right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if (left_max <= right_max)
                result += left_max - height[left++];
            else
                result += right_max - height[right--];
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