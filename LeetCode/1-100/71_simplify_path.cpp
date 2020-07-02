// smaller solution with stringstream

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> tab;
        istringstream S(path);
        string dirname;

        while (getline(S, dirname, '/'))
        {
            if (dirname.length() == 0 || dirname == ".")
                continue;
            else if (dirname == "..")
            {
                if (tab.size())
                    tab.pop_back();
            }
            else
                tab.emplace_back(dirname);
        }

        if (tab.size() == 0)
            return "/";

        string result = "";
        for (string &t : tab)
        {
            result += "/" + t;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// my first approach

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> tab;
        int i = 0, next = 0;

        while (i < path.length())
        {
            if (path[i] == '.')
            {
                next = path.find('/', i + 1);
                if (next == string::npos)
                    next = path.length();

                if (next - i == 2)
                { // go back from current directory
                    if (tab.size())
                        tab.pop_back();
                }
                else if (next - i > 2)
                { // it is a directory with dots
                    tab.emplace_back(path.substr(i, next - i));
                    i = next;
                }
                // else it is just a single dot, stay in the same directory
            }
            else if (path[i] != '/')
            { // it is a directory
                next = path.find('/', i + 1);
                if (next == string::npos)
                    next = path.length();

                tab.emplace_back(path.substr(i, next - i));
                i = next;
            }
            ++i;
        }

        string result = "/";
        for (int i = 0; i < tab.size(); ++i)
        {
            result += tab[i];
            if (i < tab.size() - 1)
                result += "/";
        }

        return result;
    }
};