#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

void addElement(vector<int> &tab, vector<pair<int, int>> &hist, int a)
{
    if (tab.empty() || a > tab.back())
    {
        tab.push_back(a);
        hist.push_back({-1, a});
    }
    else
    {
        int pos = lower_bound(tab.begin(), tab.end(), a) - tab.begin();
        int old = tab[pos];
        tab[pos] = a;
        hist.push_back({old, pos});
    }
}

int main()
{
    int n = 0, q = 0, c = 0, x = 0;
    cin >> n >> q;
    vector<int> tab;
    vector<pair<int, int>> hist;
    int pos = -1;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        addElement(tab, hist, x);
    }

    while (q--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> x;
            addElement(tab, hist, x);
        }
        else
        {
            auto tmp = hist.back();
            if (tmp.first == -1)
                tab.pop_back();
            else
            {
                tab[tmp.second] = tmp.first;
            }

            hist.pop_back();
        }
        cout << tab.size() << "\n";
    }

    return 0;
}