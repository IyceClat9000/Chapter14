// Implementation file for the FeetInches class
#include <cstdlib> // Needed for abs()
#include "FeetInches.h"

//Default Constructor
//Precondition: None
//Postcondition: private member variables feet and inches are set to 0.
FeetInches::FeetInches()
{
	feet = 0;
	inches = 0;
}
//Argument Constructor
//Precondition: f and i should be positive and i should be from a range of 1-12
//Postcondition: private member variables feet and inches are set to parameter integers f and i.
FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;
}
//Copy Constructor
//Precondition: obj should be a defined object with set integers for private member variables
//Postcondition: private member variables feet and inches are set to parameter object's feet and inches
FeetInches::FeetInches(const FeetInches& obj)
{
	feet = obj.feet;
	inches = obj.inches;
}

//Setters and Getters

//Precondition: f should be a positive number
//Postcondition: the private member variable feet is set to the given parameter
void FeetInches::setFeet(int f)
{
	feet = f;
}

//Precondition: i should preferably be from a range of 1-12
//Postcondition: the private member variable inches is set to the given parameter, if not in 1-12 range it is converted to feet and the remainder, incehs
void FeetInches::setInches(int i)
{
	inches = i;
	simplify();
}

//Precondition: None
//Postcondition: returns the private member variable feet
int FeetInches::getFeet() const
{
	return feet;
}
//Precondition: None
//Postcondition: returns the private member variable inches
int FeetInches::getInches() const
{
	return inches;
}

//Multiply Function
//Precondition: Object must be a defined class with positive feet and inches, inches should be 1-12
//Postcondition: returns a new object with the result of the parameter being mutiplied with the object calling the function
FeetInches FeetInches::multiply(const FeetInches& obj) const
{
	FeetInches temp;

	temp.feet = feet * obj.feet;
	temp.inches = inches * obj.inches;
	temp.simplify();
	return temp;
}


//**************************************************************
// Definition of member function simplify. This function       *
// checks for values in the inches member greater than         *
// twelve or less than zero. If such a value is found,         *
// the numbers in feet and inches are adjusted to conform      *
// to a standard feet & inches expression. For example,        *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and   *
// 5 feet −2 inches would be adjusted to 4 feet 10 inches.     *
//**************************************************************

//Precondition: Inches and Feet must be defined positive integers
//Postcondition: Converts the inches to the correct amount in the range of 1-12 while converting feet accordingly
void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

// Overloaded outstream operator
//Precondition: None
//Postcondition: Returns a format  (ex. Feet: 0), with feet and inches included
ostream& operator<<(ostream& out, const FeetInches& obj)
{
	out << "\n\tFeet: " << obj.getFeet();
	out << "\n\tInches: " << obj.getInches();

	return out;
}

// Overloaded + operator
//Precondition: obj must be a defined object with positive inches and feet, inches should be in the range 1-12
//Postcondition: Returns an object with the result of adding the two objects's feet and inches
FeetInches FeetInches::operator + (const FeetInches& right)
{
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}


// Overloaded − operator
//Precondition: obj must be a defined object with positive inches and feet, inches should be in the range 1-12, left object should be greater in feet preferably
//Postcondition: Returns an object with the result of subtracting the two objects's feet and inches
FeetInches FeetInches::operator - (const FeetInches& right)
{
	FeetInches temp;
	if (right.feet > feet)
	{
		temp.inches = 0;
		temp.feet = 0;
		return temp;
	}
	else if ((right.feet == feet) && (right.inches > inches))
	{
		temp.inches = 0;
		temp.feet = 0;
		return temp;
	}
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}


// Overloaded ++ operator, Prefix
//Precondition: Inches must be positive and in a range from 1-12 
//Postcondition: Increments the inches by 1 and simplifies if inches > 12 or < 1
FeetInches FeetInches:: operator ++()
{
	inches++;
	simplify();
	return(*this);
}
// Overloaded ++ operator, Postfix
//Precondition: Inches must be positive and in a range from 1-12 
//Postcondition: Increments the inches by 1 and simplifies if inches > 12 or < 1
FeetInches FeetInches:: operator ++(int)
{
	FeetInches temp(*this);
	inches++;
	simplify();
	return(temp);
}

// Overloaded -- operator, Prefix
//Precondition: Inches must be positive and in a range from 1-12 
//Postcondition: Decrements the inches by 1 and simplifies if inches > 12 or < 1
FeetInches FeetInches:: operator --()
{
	inches--;
	simplify();
	return(*this);
}
// Overloaded -- operator, Postfix
//Precondition: Inches must be positive and in a range from 1-12
//Postcondition: Decrements the inches by 1 and simplifies if inches > 12 or < 1
FeetInches FeetInches:: operator --(int)
{
	FeetInches temp(*this);
	inches--;
	simplify();
	return(temp);
}

// Overloaded = operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: Sets the left objects feet and inches to the right object in the statement
FeetInches FeetInches::operator=(const FeetInches& obj)
{
	feet = obj.getFeet();
	inches = obj.getInches();
	return(*this);
}
// Overloaded < operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: returns true if the object has less feet or less inches if the feet# are the same
bool FeetInches::operator < (const FeetInches& obj) const
{
	if (this->feet < obj.feet)
		return true;
	else if (this->feet == obj.feet)
	{
		if (this->inches < obj.inches)
			return true;
		else
			return false;
	}
	else
		return false;
}

// Overloaded == operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: returns true if the objects have the same # of feet and inches
bool FeetInches::operator == (const FeetInches& obj) const
{
	if (this->feet == obj.feet)
		if (this->inches == obj.inches)
			return true;
		else
			return false;
	else
		return false;
}

// Overloaded <= operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: returns true if the object is less than or equal to the right object
bool FeetInches::operator <= (const FeetInches& right) const
{
	return (*this < right) || (*this == right);
}

// Overloaded >= operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: returns true if the object is greater than or equal to the right object
bool FeetInches::operator >= (const FeetInches& right) const
{
	return !(*this < right);
}

// Overloaded != operator
//Precondition: object must be defined with positive inches and feet, inches should be 1-12
//Postcondition: returns true if the object is not equal to the right object
bool FeetInches::operator != (const FeetInches& right) const
{
	return !(*this == right);
}

