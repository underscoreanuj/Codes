string checkPermutation(string a, string b)
{

    vector<int> mem(128, 0);

    for (char &c : a)
        ++mem[c];

    for (char &c : b)
    {

        if (mem[c])
            --mem[c];

        else
            return "NO";
    }

    return "YES";
}
