#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

    int daysInMonth(int m, int y) const;
    bool isLeap(int y) const;

public:
    // constructors
    Date();
    Date(int m, int d, int y);

    // setters
    void setDate(int m, int d, int y);

    // getters
    int getMonth() const { return month; }
    int getDay()   const { return day; }
    int getYear()  const { return year; }

    // operators
    Date operator++();      // prefix ++
    Date operator++(int);   // postfix ++
    Date operator--();      // prefix --
    Date operator--(int);   // postfix --

    int operator-(const Date& obj) const; // subtract dates (days between)

    // I/O
    friend ostream& operator<<(ostream& out, const Date& obj);
    friend istream& operator>>(istream& in, Date& obj);
};