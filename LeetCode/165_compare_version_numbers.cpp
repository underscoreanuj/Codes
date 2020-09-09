class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<string> v1, v2;
        istringstream S1(version1), S2(version2);
        string tmp;

        while (getline(S1, tmp, '.'))
        {
            v1.emplace_back(tmp);
        }
        while (getline(S2, tmp, '.'))
        {
            v2.emplace_back(tmp);
        }

        int i = 0, j = 0, x = 0, y = 0;

        while (i < v1.size() && j < v2.size())
        {
            x = stoi(v1[i++]);
            y = stoi(v2[j++]);

            if (x > y)
                return 1;
            else if (x < y)
                return -1;
        }

        while (i < v1.size())
        {
            if (stoi(v1[i++]) > 0)
                return 1;
        }

        while (j < v2.size())
        {
            if (stoi(v2[j++]) > 0)
                return -1;
        }

        return 0;
    }
};