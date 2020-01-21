#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

unordered_map<string, int> weekdays = {
    {"Sunday", 0},
    {"Monday", 1},
    {"Tuesday", 2},
    {"Wednesday", 3},
    {"Thursday", 4},
    {"Friday", 5},
    {"Saturday", 6}};

vector<string> toPrint = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

unordered_map<string, pair<int, int>> months = {
    {"Jan", {0, 31}},
    {"Feb", {1, 28}},
    {"Mar", {2, 31}},
    {"Apr", {3, 30}},
    {"May", {4, 31}},
    {"Jun", {5, 30}},
    {"Jul", {6, 31}},
    {"Aug", {7, 31}},
    {"Sep", {8, 30}},
    {"Oct", {9, 31}},
    {"Nov", {10, 30}},
    {"Dec", {11, 31}},
};

vector<string> toIterate = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

class Date
{
public:
    string moy;
    int dom;

    Date(string moy, int dom)
    {
        this->moy = moy;
        this->dom = dom;
    }

    int operator-(const Date &obj) const
    {
        int ret = 0;
        int moy_num_src = months[this->moy].first;
        int moy_num_des = months[obj.moy].first;

        if (moy_num_src < moy_num_des)
        { // month(s) ahead
            for (int i = moy_num_src + 1; i < moy_num_des; ++i)
            {
                ret += months[toIterate[i]].second;
            }
            ret += (months[this->moy].second - this->dom) + obj.dom;
            return ret;
        }
        else if (moy_num_src > moy_num_des)
        { // month(s) behind
            for (int i = moy_num_des + 1; i < moy_num_src; ++i)
            {
                ret += months[toIterate[i]].second;
            }
            ret += (months[obj.moy].second - obj.dom) + this->dom;
            return -ret;
        }
        else
        { // same month
            ret = obj.dom - this->dom;
            return ret;
        }

        return ret;
    }
};

int main()
{

    int leapYear;
    cin >> leapYear;
    cin.ignore();
    string sourceDayOfWeek;
    string sourceMonth;
    int sourceDayOfMonth;
    cin >> sourceDayOfWeek >> sourceMonth >> sourceDayOfMonth;
    cin.ignore();
    string targetMonth;
    int targetDayOfMonth;
    cin >> targetMonth >> targetDayOfMonth;
    cin.ignore();

    if (leapYear)
        months["Feb"].second = 29;

    Date src(sourceMonth, sourceDayOfMonth);
    Date tar(targetMonth, targetDayOfMonth);

    int dayDiff = src - tar;

    if (dayDiff > 0)
        cout << toPrint[(weekdays[sourceDayOfWeek] + dayDiff) % 7] << "\n";
    else
        cout << toPrint[(weekdays[sourceDayOfWeek] + dayDiff + 364) % 7] << "\n";
}