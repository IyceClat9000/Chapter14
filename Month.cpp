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

//Precondition: new valid month name
//Postcondition: set the obj name and number to valid name and number or 0/unknown
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

//Precondition: N/A
//Postcondition: return the name
string Month::getName() const
{
	return name;
}

//Precondition: new valid month number
//Postcondition: set the obj name and number to valid name and number or 0/unknown
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

//Precondition: N/A
//Postcondition: return the monthNumber
int Month::getMonthNumber() const
{
	return monthNumber;
}

//Precondition: N/A
//Postcondition: increment the month to next month and return the incremented month
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

//Precondition: N/A
//Postcondition: return the original month then increment the month to next month
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

//Precondition: N/A
//Postcondition: decrement the month to previous month and return the decremented month
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

//Precondition: N/A
//Postcondition: return the original month then decrement the month to previous month
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

//Precondition: a positive integer
//Postcondition: return the incremented month
Month Month::operator+(const int n) const
{
	Month temp(*this);
	for (int i = 0; i < n; i++)
		++temp;
	return temp;
}

//Precondition: a positive integer
//Postcondition: return the decremented month
Month Month::operator-(const int n) const
{
	Month temp(*this);
	for (int i = 0; i < n; i++)
		--temp;
	return temp;
}

//Precondition: a valid month object
//Postcondition: return the deep copied month
Month Month::operator=(const Month& obj)
{
	monthNumber = obj.getMonthNumber();
	name = obj.getName();
	return *this;
}

//Precondition: a valid month object
//Postcondition: return true/false
bool Month::operator<(const Month& obj) const
{
	return(monthNumber < obj.getMonthNumber() ? true : false);
}

//Precondition: a valid month object
//Postcondition: return the deep copied month
bool Month::operator==(const Month& obj) const
{
	return(monthNumber == obj.getMonthNumber() ? true : false);
}

//Precondition: a valid month object
//Postcondition: display the month name and month number in a new line
ostream& operator<<(ostream& out, const Month& obj)
{
	out << "\n\tMonth Name: " << obj.getName();
	out << "\n\tMonth Number: " << obj.getMonthNumber();

	return out;
}