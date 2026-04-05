#pragma once
#include <string>
using namespace std;

class Month
{
private:
	string name;
	int monthNumber;
	

public:
	Month() // Default Constructor
	{
		name = "Unknown";
		monthNumber = 0;
	}

	Month(int n) // Argument Constructor
	{
		setMonthNumber(n);
	}

	Month(const Month& obj) // Copy Constructor
	{
		name = obj.name;
		monthNumber = obj.monthNumber;
	}

	void setName(string newName)
	{		
		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		name = names[0];
		monthNumber = 0;

		for (int i = 0; i < 13; i++)
		{
			if (names[i] == newName)
			{
				name = names[i];
				monthNumber = i;
				break;
			}				
		}		
	}

	string getName() const
	{
		return name;
	}

	void setMonthNumber(int n)
	{
		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		if (n >= 1 && n <= 12)
		{
			monthNumber = n;
			name = names[n];
		}
		else
		{
			monthNumber = 0;
			name = names[0];
		}
	}

	int getMonthNumber() const
	{
		return monthNumber;
	}

	Month operator++() // Overload Prefix ++
	{
		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		monthNumber++;

		if (monthNumber > 12)
		{
			monthNumber = 1;
			name = names[1];
		}
		else
		{
			name = names[monthNumber];
		}

		return *this;
	}

	Month operator++(int ) // Overload Postfix ++
	{
		Month temp(*this);

		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		monthNumber++;

		if (monthNumber > 12)
		{
			monthNumber = 1;
			name = names[1];
		}
		else
		{
			name = names[monthNumber];
		}

		return temp;
	}

	Month operator--() // Overload Prefix --
	{
		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		monthNumber--;

		if (monthNumber < 1)
		{
			monthNumber = 12;
			name = names[12];
		}
		else
		{
			name = names[monthNumber];
		}

		return *this;
	}

	Month operator--(int) // Overload Postfix --
	{
		Month temp(*this);

		string names[] = { "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		monthNumber--;

		if (monthNumber < 1)
		{
			monthNumber = 12;
			name = names[12];
		}
		else
		{
			name = names[monthNumber];
		}

		return temp;
	}

	friend ostream& operator<<(ostream& out, const Month& obj); // Overload << using friend

	Month operator=(const Month& obj)
	{
		monthNumber = obj.getMonthNumber();
		name = obj.getName();
	}

	Month operator-(const int n)
	{
		Month temp = *this;
		for (int i = 0; i < n; i--)
			temp--;

		return temp;
	}

	Month operator+(const int n)
	{
		Month temp = *this;
		for (int i = 0; i < n; i++)
			temp++;

		return temp;
	}

	bool operator<(const Month& obj)
	{
		return (this->monthNumber < obj.getMonthNumber() ? true : false);
	}

	bool operator==(const Month& obj)
	{
		return (this->monthNumber == obj.getMonthNumber() ? true : false);
	}

};

ostream& operator<<(ostream& out, const Month& obj)
{
	out << "\n\tMonth Name: " << obj.getName();
	out << "\n\tMonth Number: " << obj.getMonthNumber();

	return out;
}