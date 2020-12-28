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