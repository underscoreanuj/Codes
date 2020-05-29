string stringRotation(string a, string b)
{

    string tmp = a + a;

    if (tmp.find(b) != string::npos)
        return "YES";

    return "NO";
}
