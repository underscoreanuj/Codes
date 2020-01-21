#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string encode(string m)
{
    int n = m.length();
    int i = 0, ct = 1;
    deque<string> ret;

    while (i < n)
    {
        if (ct & 1) // push back
            ret.push_back(m.substr(i, min(n - i, ct)));
        else // push front
            ret.push_front(m.substr(i, min(n - i, ct)));

        i += ct;
        ++ct;
    }

    string encoded_string;
    for (auto s : ret)
        encoded_string += s;

    return encoded_string;
}

string decode(string m)
{
    int n = m.length();
    int i = 0, ct = 1, p_length = 1;

    deque<string> ret;

    while (p_length < n)
    {
        p_length += (ct + 1);
        ++ct;
    }

    int init_len = ct - (p_length - n);

    if (ct & 1)
    { // last element at back
        ret.push_front(m.substr(n - init_len, init_len));
        n -= init_len;
        init_len = 0;
    }
    else
    { // last element at front
        ret.push_front(m.substr(0, init_len));
    }

    while (ct--)
    {
        if (ct & 1)
        { // last element at back
            ret.push_front(m.substr(n - ct, ct));
            n -= ct;
        }
        else
        { // last element at front
            ret.push_front(m.substr(init_len, ct));
            init_len += ct;
        }
    }

    string decoded_string;
    for (auto s : ret)
        decoded_string += s;

    return decoded_string;
}

int main()
{

    int N;
    cin >> N;
    cin.ignore();
    string MESSAGE;
    getline(cin, MESSAGE);

    if (N < 0)
    { // encode
        while (N++)
            MESSAGE = encode(MESSAGE);
    }
    else if (N > 0)
    { // decode
        while (N--)
            MESSAGE = decode(MESSAGE);
    }

    cout << MESSAGE << "\n";
}