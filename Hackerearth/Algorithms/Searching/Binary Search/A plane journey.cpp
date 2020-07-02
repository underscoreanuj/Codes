#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool isValid(vector<int> &GR, vector<int> &PL, int time)
{
    int count = 0;
    for (int i = 0; i < PL.size(); ++i)
    {
        for (int j = 0; j < time && count < GR.size() && PL[i] >= GR[count]; j += 2)
            ++count;
    }

    return count == GR.size();
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> groups(n, 0);
    vector<int> planes(m, 0);

    for (int i = 0; i < n; ++i)
        cin >> groups[i];
    for (int i = 0; i < m; ++i)
        cin >> planes[i];

    sort(groups.begin(), groups.end());
    sort(planes.begin(), planes.end());

    if (groups[groups.size() - 1] > planes[planes.size() - 1])
    {
        cout << "-1";
        return 0;
    }

    int l = 1, r = 2 * (n - 1) + 1, mid = 0;

    while (l < r)
    {
        mid = l + ((r - l) >> 1);

        if (isValid(groups, planes, mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}