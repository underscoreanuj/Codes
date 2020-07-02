#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
public:
    int day;
    int month;
    int year;

    Date(string date)
    {
        this->day = stoi(date.substr(0, 2));
        this->month = stoi(date.substr(3, 2));
        this->year = stoi(date.substr(6, 4));
    }

    bool operator>(Date obj)
    {
        if (this->year > obj.year)
            return true;
        else if (this->year == obj.year)
        {
            if (this->month > obj.month)
                return true;
            else if (this->month == obj.month)
            {
                return this->day >= obj.day;
            }
        }
        return false;
    }

    void operator-(Date obj)
    {
        int y_diff = 0, m_diff = 0, d_diff = 0;
        y_diff = this->year - obj.year;
        m_diff = this->month - obj.month;
        if (m_diff < 0)
        {
            m_diff = (m_diff + 12) % 12;
            --y_diff;
        }
        d_diff = this->day - obj.day;
        if (d_diff < 0)
        {
            --m_diff;
        }
        cerr << "\n ++++++++    " << y_diff << " ::  " << m_diff << " ::  " << d_diff << "\n";

        d_diff = 0;

        int y_days = 0;
        int m_days_o = 0;
        int m_days_t = 0;

        for (int i = obj.year + 1; i < this->year; ++i)
        {
            y_days += 365;
            if (i % 4 == 0)
                ++y_days;
        }

        cerr << "\n ............ y_days    " << y_days << "\n";

        if (this->year == obj.year)
        {
            for (int i = obj.month + 1; i < this->month; ++i)
            {
                if (i == 2 && obj.year % 4 == 0)
                    ++m_days_o;
                m_days_o += month_days[i - 1];
            }
            cerr << "\n ............m_days_o _ same year    " << m_days_o << "\n";
        }
        else
        {
            for (int i = obj.month + 1; i <= 12; ++i)
            {
                if (i == 2 && obj.year % 4 == 0)
                    ++m_days_o;
                m_days_o += month_days[i - 1];
            }

            cerr << "\n ............m_days_o    " << m_days_o << "\n";

            for (int i = 1; i < this->month; ++i)
            {
                if (i == 2 && this->year % 4 == 0)
                    ++m_days_t;
                m_days_t += month_days[i - 1];
            }

            cerr << "\n ............m_days_t    " << m_days_t << "\n";
        }

        d_diff = y_days + m_days_o + m_days_t;

        if (this->year == obj.year && this->month == obj.month)
        {
            d_diff += this->day - obj.day;
        }
        else
        {
            d_diff += month_days[obj.month - 1] - obj.day;
            if (obj.month == 2 && obj.year % 4 == 0)
                ++d_diff;
            d_diff += this->day;
        }

        if (y_diff > 0)
            cout << y_diff << ((y_diff > 1) ? " years, " : " year, ");
        if (m_diff > 0)
            cout << m_diff << ((m_diff > 1) ? " months, " : " month, ");

        cout << "total " << d_diff << " days";
    }
};

int main()
{
    string BEGIN;
    cin >> BEGIN;
    cin.ignore();
    string END;
    cin >> END;
    cin.ignore();

    Date begin(BEGIN);
    Date end(END);

    if (begin > end)
        begin - end;
    else
        end - begin;
}