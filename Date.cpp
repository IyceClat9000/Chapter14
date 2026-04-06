#include "Date.h"
#include <cmath>

// Default constructor
// Initializes date to January 1, year 0
Date::Date()
{
    month = 1;
    day = 1;
    year = 0;
}

// Parameterized constructor
// Calls setDate to validate and assign values
Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

// Checks if a given year is a leap year
// Returns true if leap year, false otherwise
bool Date::isLeap(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Returns number of days in a given month and year
// Accounts for leap years in February
int Date::daysInMonth(int m, int y) const
{
    if (m == 2)
        return isLeap(y) ? 29 : 28;

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;

    return 31;
}

// Sets the date with validation
// If invalid values are provided, defaults are assigned
void Date::setDate(int m, int d, int y)
{
    // Validate month
    if (m < 1 || m > 12)
    {
        cout << "\nERROR: Invalid month. Defaulting to 1.";
        month = 1;
    }
    else
        month = m;

    // Validate year
    if (y < 0)
    {
        cout << "\nERROR: Invalid year. Defaulting to 0.";
        year = 0;
    }
    else
        year = y;

    // Validate day based on month/year
    if (d < 1 || d > daysInMonth(month, year))
    {
        cout << "\nERROR: Invalid day. Defaulting to 1.";
        day = 1;
    }
    else
        day = d;
}

// Helper function to convert a Date object into total number of days
// Used for date comparisons and subtraction
// Uses getters instead of accessing private members directly
int toDays(Date d)
{
    int total = d.getDay();   // Start with current day

    // Add days for all previous years
    for (int y = 0; y < d.getYear(); y++)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            total += 366; // Leap year
        else
            total += 365; // Normal year
    }

    // Days in each month (index 0 unused)
    int daysInMonthArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    // Add days for all previous months in current year
    for (int m = 1; m < d.getMonth(); m++)
    {
        int y = d.getYear();
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
            total += 29; // Leap year February
        else
            total += daysInMonthArr[m];
    }

    return total;
}

// Prefix increment operator (++date)
// Advances the date by one day
Date Date::operator++()
{
    day++;

    // Handle overflow of days
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;

        // Handle overflow of months
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

// Postfix increment operator (date++)
// Returns old value, then increments
Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

// Prefix decrement operator (--date)
// Moves the date back by one day
Date Date::operator--()
{
    day--;

    // Handle underflow of days
    if (day < 1)
    {
        month--;

        // Handle underflow of months
        if (month < 1)
        {
            month = 12;
            year--;
        }

        day = daysInMonth(month, year);
    }
    return *this;
}

// Postfix decrement operator (date--)
// Returns old value, then decrements
Date Date::operator--(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

// Overloaded subtraction operator
// Returns the difference in days between two dates
int Date::operator-(const Date& obj) const
{
    return abs(toDays(*this) - toDays(obj));
}

// Output stream operator (cout << date)
// Displays date in "Month Day, Year" format
ostream& operator<<(ostream& out, const Date& obj)
{
    string months[] = { "", "January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December" };

    out << months[obj.month] << " " << obj.day << ", " << obj.year;
    return out;
}

// Input stream operator (cin >> date)
// Prompts user until a valid date is entered
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

        // Validate month and year
        if (m < 1 || m > 12 || y < 0)
        {
            cout << "\nERROR: Invalid month or year. Please try again.";
            continue;
        }

        // Determine max days in given month/year
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

        // Validate day
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
