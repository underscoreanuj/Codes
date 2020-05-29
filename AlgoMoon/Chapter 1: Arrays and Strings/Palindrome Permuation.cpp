string palindromePermutation(string s)
{

    vector<int> mem(128, 0);

    bool flag = false;

    for (char &c : s)
        ++mem[c];

    for (int i = 0; i < mem.size(); ++i)
    {

        if (mem[i] % 2)
        {

            if (s.length() % 2)
            {

                if (flag)
                    return "NO";

                else
                    flag = true;
            }

            else
                return "NO";
        }
    }

    return "YES";
}
