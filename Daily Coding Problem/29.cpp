/**
 * 
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 * Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
 * Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string encode(string s)
{
    string res = "";
    int i = 0, count = 0;

    while (i < s.length())
    {
        count = 1;
        while (i + count < s.length() && s[i] == s[i + count])
            ++count;

        res += to_string(count) + s[i];
        i += count;
    }

    return res;
}

string decode(string s)
{
    string res = "";
    int i = 0, count = 0;

    while (i < s.length())
    {
        count = s[i] - '0';
        res.append(count, s[i + 1]);

        i += 2;
    }

    return res;
}

int main()
{
    string t1 = "AAAABBBCCDAA";
    string r1 = "4A3B2C1D2A";

    assert(("empty string encode error", encode("") == ""));
    assert(("simple encode error", encode("AAA") == "3A"));

    assert(("empty string decode error", decode("") == ""));
    assert(("simple decode error", decode("3A") == "AAA"));

    assert(("encoding error", encode(t1) == r1));
    assert(("decoding error", decode(r1) == t1));
    assert(("encode -> decode [complement error]", decode(encode(t1)) == t1));
    assert(("decode -> encode [complement error]", encode(decode(r1)) == r1));

    return 0;
}
