#include "Month.h"

//Precondition: N/A
//Postcondition: Set private members: name = "unknown", monthNumber = 0
Month::Month()
{
	name = "unknown";
	monthNumber = 0;
}

//Precondition: N/A
//Postcondition: Set private members: name = name of the month in array or "unknown", monthNumber = n or 0 
Month::Month(int n)
{
	setMonthNumber(n);
}

//Precondition: valid Month object
//Postcondition: copy the Month obj to the new Month
Month::Month(const Month& obj)
{
	name = obj.name;
	monthNumber = obj.monthNumber;
}

void Month::setName(string newName)
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
string Month::getName() const
{
	return name;
}

void Month::setMonthNumber(int n)
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
int Month::getMonthNumber() const
{
	return monthNumber;
}

Month Month::operator++() // Overload Prefix ++
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
Month Month::operator++(int)
{
	Month temp(*this); //hold a temp here

	//increment everything
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

	//return temp still the same, although members are already incremented
	return temp;
}

Month Month::operator--()
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
Month Month::operator--(int)
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

Month Month::operator+(const int n) const
{
	Month temp(*this);
	for (int i = 0; i < n; i++)
		++temp;
	return temp;
}

Month Month::operator-(const int n) const
{
	Month temp(*this);
	for (int i = 0; i < n; i++)
		--temp;
	return temp;
}

Month Month::operator=(const Month& obj)
{
	monthNumber = obj.getMonthNumber();
	name = obj.getName();
	return *this;
}

bool Month::operator<(const Month& obj) const
{
	return(monthNumber < obj.getMonthNumber() ? true : false);
}

bool Month::operator==(const Month& obj) const
{
	return(monthNumber == obj.getMonthNumber() ? true : false);
}

ostream& operator<<(ostream& out, const Month& obj)
{
	out << "\n\tMonth Name: " << obj.getName();
	out << "\n\tMonth Number: " << obj.getMonthNumber();

	return out;
}