class Solution
{
public:
    string validIPAddress(string IP)
    {
        int dot_count = 0, colon_count = 0;
        for (char &c : IP)
        {
            if (c == '.')
                ++dot_count;
            if (c == ':')
                ++colon_count;
        }

        stringstream S(IP);
        string tmp;
        int val = 0, count = 0;

        if (dot_count == 3 && colon_count == 0)
        { // possible IPv4
            while (getline(S, tmp, '.'))
            {
                for (char &c : tmp)
                    if (!isdigit(c))
                        return "Neither";
                if (tmp.length() == 0 || tmp.length() > 3 || (tmp[0] == '0' && tmp.length() > 1) || stoi(tmp) > 255)
                    return "Neither";
                ++count;
            }
            return count == 4 ? "IPv4" : "Neither";
        }
        else if (dot_count == 0 && colon_count == 7)
        { // possible IPv6
            while (getline(S, tmp, ':'))
            {
                for (char &c : tmp)
                    if (!isdigit(c) && !(tolower(c) >= 'a' && tolower(c) <= 'f'))
                        return "Neither";
                stringstream ss;
                ss << hex << tmp;
                ss >> val;
                if (tmp.length() > 4 || tmp.length() == 0 || val > 65535)
                    return "Neither";
                ++count;
            }
            return count == 8 ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();