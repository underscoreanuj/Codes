string stringCompression(string s)
{

    string compressed = "";
    int count = 0, i = 0;

    while (i < s.length())
    {
        count = 1;
        while (i + count < s.length() && s[i] == s[i + count])
            ++count;

        compressed.push_back(s[i]);
        compressed.push_back((count + '0'));

        i += count;
    }

    return compressed.length() <= s.length() ? compressed : s;
}