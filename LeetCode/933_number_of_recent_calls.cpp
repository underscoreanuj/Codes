// queue based solution

class RecentCounter
{
public:
    queue<int> Q;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        Q.push(t);
        while (Q.front() < t - 3000)
            Q.pop();

        return Q.size();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// binary search based solution

class RecentCounter
{
public:
    vector<int> calls;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        int result = lower_bound(calls.begin(), calls.end(), t - 3000) - calls.begin();
        calls.emplace_back(t);
        return calls.size() - result;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */