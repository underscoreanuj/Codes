#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int> &BX, vector<int> &TR, int time)
{
    int count = 0;
    for (int i = 0; i < TR.size(); ++i)
    {
        for (int j = 0; j < time && count < BX.size() && TR[i] >= BX[count]; j += 2)
            ++count;
    }

    return count == BX.size();
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> boxes(n, 0);
    vector<int> trucks(m, 0);
    vector<bool> vis(m, false);

    for (int i = 0; i < n; ++i)
        cin >> boxes[i];
    for (int i = 0; i < m; ++i)
        cin >> trucks[i];

    sort(boxes.begin(), boxes.end());
    sort(trucks.begin(), trucks.end());

    int l = 1, r = 2 * (n - 1) + 1, mid = 0;

    while (l < r)
    {
        mid = l + ((r - l) >> 1);

        if (isValid(boxes, trucks, mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}