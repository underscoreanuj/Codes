// divide and conquer solution

class Solution
{
public:
    void swapPoints(vector<int> &a, vector<int> &b)
    {
        vector<int> tmp = a;
        a = b;
        b = tmp;
    }

    int distance(vector<int> &a)
    {
        return (a[0] * a[0] + a[1] * a[1]);
    }

    int partition(vector<vector<int>> &points, int l, int r)
    {
        vector<int> pivot = points[l];
        int pivot_dist = distance(pivot);

        int j = l + 1;
        for (int i = l + 1; i <= r; ++i)
        {
            if (distance(points[i]) <= pivot_dist)
            {
                swap(points[i], points[j]);
                ++j;
            }
        }
        swap(points[l], points[j - 1]);

        return j - 1;
    }

    void sort(vector<vector<int>> &points, int K, int l, int r)
    {
        if (l >= r)
            return;

        int p = partition(points, l, r);

        if (p < K)
            sort(points, K, p + 1, r);
        else if (p > K)
            sort(points, K, l, p - 1);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        --K;
        sort(points, K, 0, points.size() - 1);

        return vector<vector<int>>(points.begin(), points.begin() + K + 1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// nth_element solution

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        --K;
        nth_element(points.begin(), points.begin() + K, points.end(),
                    [](const vector<int> &a, const vector<int> &b) {
                        return (sqrt(a[0] * a[0] + a[1] * a[1]) < sqrt(b[0] * b[0] + b[1] * b[1]));
                    });

        vector<vector<int>> result;
        result.push_back(points[K]);
        double kth_dist = sqrt(points[K][0] * points[K][0] + points[K][1] * points[K][1]);

        for (int i = 0; i < points.size(); ++i)
        {
            if (result.size() == K + 1)
                break;
            if (i != K && sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]) <= kth_dist)
                result.emplace_back(points[i]);
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

// priority queue solution

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        auto myCompare = [](const pair<int, int> &a, const pair<int, int> &b) {
            return (sqrt(a.first * a.first + a.second * a.second) < sqrt(b.first * b.first + b.second * b.second));
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCompare)> PQ(myCompare);
        vector<vector<int>> result;

        for (auto &p : points)
        {
            PQ.push({p[0], p[1]});
            if (PQ.size() > K)
                PQ.pop();
        }

        while (PQ.size())
        {
            result.push_back({PQ.top().first, PQ.top().second});
            PQ.pop();
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