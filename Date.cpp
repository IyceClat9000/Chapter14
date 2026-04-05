#include "Date.h"
#include <cmath>

Date::Date()
{
    month = 1;
    day = 1;
    year = 0;
}

Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

bool Date::isLeap(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const
{
    if (m == 2)
        return isLeap(y) ? 29 : 28;

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;

    return 31;
}

void Date::setDate(int m, int d, int y)
{
    if (m < 1 || m > 12)
    {
        cout << "\nERROR: Invalid month. Defaulting to 1.";
        month = 1;
    }
    else
        month = m;

    if (y < 0)
    {
        cout << "\nERROR: Invalid year. Defaulting to 0.";
        year = 0;
    }
    else
        year = y;

    if (d < 1 || d > daysInMonth(month, year))
    {
        cout << "\nERROR: Invalid day. Defaulting to 1.";
        day = 1;
    }
    else
        day = d;
}

// toDays is now a plain helper function.
// Instead of accessing private members directly, it uses the public getters.
// No friend needed.
int toDays(Date d)
{
    int total = d.getDay();   // using getter instead of d.day

    for (int y = 0; y < d.getYear(); y++)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            total += 366;
        else
            total += 365;
    }

    int daysInMonthArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    for (int m = 1; m < d.getMonth(); m++)
    {
        int y = d.getYear();
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
            total += 29;
        else
            total += daysInMonthArr[m];
    }

    return total;
}

Date Date::operator++()
{
    day++;

    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;

        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date Date::operator--()
{
    day--;

    if (day < 1)
    {
        month--;

        if (month < 1)
        {
            month = 12;
            year--;
        }

        day = daysInMonth(month, year);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

int Date::operator-(const Date& obj) const
{
    return abs(toDays(*this) - toDays(obj));
}

ostream& operator<<(ostream& out, const Date& obj)
{
    string months[] = { "", "January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December" };

    out << months[obj.month] << " " << obj.day << ", " << obj.year;
    return out;
}

istream& operator>>(istream& in, Date& obj)
{
    int m, d, y;
    bool valid = false;

    while (!valid)
    {
        cout << "\nEnter month (1-12): ";
        in >> m;

        cout << "Enter year (0+):    ";
        in >> y;

        if (m < 1 || m > 12 || y < 0)
        {
            cout << "\nERROR: Invalid month or year. Please try again.";
            continue;
        }

        // Figure out how many days this month actually has
        int maxDays;
        bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (m == 2)
            maxDays = leap ? 29 : 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            maxDays = 30;
        else
            maxDays = 31;

        cout << "Enter day (1-" << maxDays << "): ";
        in >> d;

        if (d < 1 || d > maxDays)
        {
            cout << "\nERROR: Invalid day for that month/year. Please try again.";
            continue;
        }

        valid = true;
    }

    obj.setDate(m, d, y);
    return in;
}