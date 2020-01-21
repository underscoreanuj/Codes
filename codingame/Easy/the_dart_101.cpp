#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> splitString(string s, char c)
{
    vector<string> ret;
    size_t cur_pos = 0;
    size_t pos = s.find(c);

    if (pos == string::npos)
        return ret;

    while (pos != string::npos)
    {
        ret.push_back(s.substr(cur_pos, pos - cur_pos));
        cur_pos = pos + 1;

        pos = s.find(c, cur_pos);
    }

    ret.push_back(s.substr(cur_pos, s.length() - cur_pos));

    return ret;
}

int getProcessedNumber(string s)
{
    if (s == "X")
        return -20;
    if (s.find('*') == string::npos)
        return stoi(s);

    vector<string> mul = splitString(s, '*');

    int ret = 1;
    for (auto m : mul)
        ret *= stoi(m);

    return ret;
}

int getLastRound(string streak)
{
    vector<string> plays = splitString(streak, ' ');
    vector<int> playScores;

    for_each(plays.begin(), plays.end(), [&playScores](const string &o) {
        playScores.push_back(getProcessedNumber(o));
    });

    int score = 0;
    int prev_round_score = 0;
    int num_rounds = 0;
    int n = playScores.size();
    int i = 0, j = 0;

    for (i = 0; i < n; ++i)
    {
        ++num_rounds;

        for (j = i; j < min(n, i + 3); ++j)
        {
            int tmp = playScores[j];

            if (tmp == -20 && j > i && playScores[j - 1] == -20)
            {
                tmp = -30;
                if (j - 1 > i && playScores[j - 2] == -20)
                {
                    tmp = score * -1;
                }
            }

            score += tmp;

            if (score == 101)
                return num_rounds;

            if (score > 101)
            {
                score = prev_round_score;
                ++j;
                break;
            }
        }

        prev_round_score = score;
        i = j - 1;
    }

    return 999999;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<pair<string, int>> players;

    for (int i = 0; i < N; i++)
    {
        string PLAYER;
        getline(cin, PLAYER);

        players.push_back({PLAYER, 0});
    }

    for (int i = 0; i < N; i++)
    {
        string SHOOTS;
        getline(cin, SHOOTS);

        players[i].second = getLastRound(SHOOTS);
    }

    int idx = 0;
    for (int i = 1; i < N; ++i)
    {
        if (players[i].second < players[idx].second)
            idx = i;
    }

    cout << players[idx].first << "\n";
}