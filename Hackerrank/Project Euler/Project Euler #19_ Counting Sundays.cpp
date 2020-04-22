#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

vector<int> monthMap = {-1, 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};

class Date
{
public:
    ll year;
    int month;
    int day;
    Date(ll year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    bool operator>(const Date &o)
    {
        if (this->year > o.year)
            return true;
        else if (this->year == o.year && this->month > o.month)
            return true;
        else if (this->year == o.year && this->month == o.month && this->day > o.day)
            return true;
        return false;
    }
};

bool isLeapYear(ll y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int Zellercongruence(int day, int month, ll year)
{
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    ll k = year % 100;
    ll j = year / 100;
    ll h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h %= 7;
    h += 6;
    h %= 7;
    return h;
}

int getSundayCount(Date &d1, Date &d2)
{
    if (d1 > d2)
        return getSundayCount(d2, d1);

    ll start = Zellercongruence(1, 1, d1.year);

    int result = 0;

    if (d1.year == d2.year)
    {
        for (int m = 1; m <= d2.month; ++m)
        {
            if (start == 0 && (m > d1.month || (m == d1.month && d1.day == 1)))
                ++result;
            if (m == 2 && isLeapYear(d1.year))
                start += 1;
            else
                start += monthMap[m];

            start %= 7;
        }
        return result;
    }

    for (int m = 1; m <= 12; ++m)
    {
        if (start == 0 && (m > d1.month || (m == d1.month && d1.day == 1)))
            ++result;
        if (m == 2 && isLeapYear(d1.year))
            start += 1;
        else
            start += monthMap[m];

        start %= 7;
    }

    for (size_t y = d1.year + 1; y < d2.year; ++y)
    {
        for (int m = 1; m <= 12; ++m)
        {
            if (start == 0)
                ++result;
            if (m == 2 && isLeapYear(y))
                start += 1;
            else
                start += monthMap[m];

            start %= 7;
        }
    }

    for (int m = 1; m <= d2.month; ++m)
    {
        if (start == 0)
            ++result;
        if (m == 2 && isLeapYear(d2.year))
            start += 1;
        else
            start += monthMap[m];

        start %= 7;
    }

    return result;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, m = 0, d = 0;
    ll y;
    cin >> t;

    while (t--)
    {
        cin >> y >> m >> d;
        Date d1(y, m, d);
        cin >> y >> m >> d;
        Date d2(y, m, d);

        cout << getSundayCount(d1, d2) << "\n";
    }

    return 0;
}
