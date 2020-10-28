#include <iostream>

using namespace std;

#define ll long long int

int main()
{
    ll n = 0, t = 0, count = 0;

    cin >> t;

    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;
        count = 0;

        for (char c : s)
        {
            if (c == '0')
                ++count;
        }

        cout << count << "\n";
    }

    return 0;
}