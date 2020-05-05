#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n = 0, c = 0, p = 0;
    cin >> n;
    vector<int> a;

    while (n--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> p;
            a.insert(upper_bound(a.begin(), a.end(), p), p);
        }
        else
        {
            if (a.size() < 3)
                cout << "Not enough enemies\n";
            else
            {
                cout << a[a.size() - (a.size() / 3)] << "\n";
            }
        }
    }

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// auto speedup = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

// int main()
// {
//     int n = 0, c = 0, p = 0;
//     cin >> n;
//     vector<int> a;

//     while (n--)
//     {
//         cin >> c;
//         if (c == 1)
//         {
//             cin >> p;
//             a.push_back(p);
//         }
//         else
//         {
//             if (a.size() < 3)
//                 cout << "Not enough enemies\n";
//             else
//             {
//                 nth_element(a.begin(), a.begin() + ((a.size() / 3) - 1), a.end(), greater<int>());
//                 cout << a[(a.size() / 3) - 1] << "\n";
//             }
//         }
//     }

//     return 0;
// }