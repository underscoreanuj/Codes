// dfs approach

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (start >= 0 && start < arr.size() && arr[start] >= 0)
        {
            if (arr[start] == 0)
                return true;
            arr[start] = -arr[start];
            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// bfs approach

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int cur_idx = 0, left_idx = 0, right_idx = 0;
        queue<int> Q;
        Q.push(start);

        while (Q.size())
        {
            cur_idx = Q.front();
            Q.pop();

            if (arr[cur_idx] == 0)
                return true;
            if (arr[cur_idx] < 0)
                continue;

            left_idx = cur_idx - arr[cur_idx];
            right_idx = cur_idx + arr[cur_idx];

            if (left_idx >= 0)
                Q.push(left_idx);
            if (right_idx < arr.size())
                Q.push(right_idx);

            arr[cur_idx] = -arr[cur_idx];
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();