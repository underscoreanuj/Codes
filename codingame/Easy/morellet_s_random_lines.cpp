#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Line
{
public:
    int a;
    int b;
    int c;
    Line(int a, int b, int c)
    {
        int gg = __gcd(__gcd(a, b), c);
        this->a = a / gg;
        this->b = b / gg;
        this->c = c / gg;
    }

    bool operator==(const Line &obj) const
    {
        return (this->a == obj.a && this->b == obj.b && this->c == obj.c);
    }

    int solve(int x, int y)
    {
        return x * this->a + y * this->b + this->c;
    }
};

class MyHash
{
public:
    size_t operator()(const Line &obj) const
    {
        return hash<int>()(obj.a) ^ hash<int>()(obj.b) ^ hash<int>()(obj.c);
    }
};

int main()
{
    int xA;
    int yA;
    int xB;
    int yB;
    cin >> xA >> yA >> xB >> yB;
    cin.ignore();
    int n;
    cin >> n;
    cin.ignore();

    unordered_set<Line, MyHash> L;

    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        cin.ignore();

        Line obj(a, b, c);

        if (L.find(obj) == L.end())
            L.insert(obj);
    }

    int res = 1;

    for (auto l : L)
    {
        int sa = l.solve(xA, yA);
        int sb = l.solve(xB, yB);
        if (sa == 0 || sb == 0)
        {
            cout << "ON A LINE\n";
            return 0;
        }

        res *= (sa * sb < 0 ? -1 : 1);
    }

    if (res < 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}