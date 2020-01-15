#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    int min_x = 999999, max_x = -999999;
    long long int total_length = 0;

    vector<pair<int, int>> B;

    for (int i = 0; i < N; i++)
    {
        int X;
        int Y;
        cin >> X >> Y;
        cin.ignore();
        B.push_back({X, Y});

        min_x = min(min_x, X);
        max_x = max(max_x, X);
    }

    total_length += max_x - min_x;

    auto median = B.begin() + N / 2;
    nth_element(B.begin(), median, B.end(), [](const pair<int, int> o1, const pair<int, int> o2) {
        return o1.second < o2.second;
    });

    for (int i = 0; i < N; i++)
    {
        total_length += abs(B[i].second - (median->second));
    }

    cout << total_length << endl;
}