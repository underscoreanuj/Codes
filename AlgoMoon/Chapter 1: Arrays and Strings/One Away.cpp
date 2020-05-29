string oneAway(string a, string b)
{

    if (a.length() > b.length())
        return oneAway(b, a);

    if (b.length() - a.length() > 1)
        return "NO";

    bool flag = false;

    if (a.length() == b.length())
    {

        // replace a character

        for (int i = 0; i < a.length(); ++i)
        {

            if (a[i] != b[i])
            {

                if (flag)
                    return "NO";

                else
                    flag = true;
            }
        }
    }

    else
    {

        vector<int> mem(128, 0);

        for (char &c : a)
            ++mem[c];

        for (char &c : b)
            --mem[c];

        for (int &m : mem)
        {

            if (m < 0)
            {

                if (flag)
                    return "NO";

                else
                    flag = true;
            }
        }
    }

    return "YES";
}
