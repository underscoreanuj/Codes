void trim(string &s)
{

    int i = s.length() - 1;

    while (s[i] == ' ')
        --i;

    s = s.substr(0, i + 1);
}

string urlify(int n, string s)
{

    trim(s);

    for (int i = 0; i < s.length(); ++i)
    {

        if (s[i] == ' ')
        {

            s[i++] = '%';

            s.insert(i, "20");
        }
    }

    return s;
}
