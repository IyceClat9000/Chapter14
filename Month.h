#pragma once
#include<string>
#include<iostream>
using namespace std;

class Month
{
private:
	string name;
	int monthNumber;

public:
	//Precondition: N/A
	//Postcondition: Set private members: name = "unknown", monthNumber = 0
	Month();
	Month(int n);
	Month(const Month& obj);

	void setName(string newName);
	string getName() const;

	void setMonthNumber(int n);
	int getMonthNumber() const;

	Month operator++(); //++Prefix
	Month operator++(int); //Postfix++

	Month operator--(); //--Prefix
	Month operator--(int); //Postfix--

	Month operator+(const int n) const;
	Month operator-(const int n) const;

	Month operator=(const Month& obj);
	bool operator<(const Month& obj) const;
	bool operator==(const Month& obj) const;

	friend ostream& operator<<(ostream& out, const Month& obj);
};

ostream& operator<<(ostream& out, const Month& obj);