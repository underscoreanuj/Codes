string isUnique(string s)
{

    vector<bool> mem(256, false);

    for (char &c : s)
    {

        if (mem[c])
            return "NO";

        mem[c] = true;
    }

    return "YES";
}
