#include "LandTract.h"

// Default Constructor
// Precondition: None
// Postcondition: length and width are set to 0 feet and 0 inches
LandTract::LandTract()
{
	length = FeetInches(0, 0);
	width = FeetInches(0, 0);
}

// Argument Constructor
// Precondition: l and w should be defined objects with positive feet and inches, inches should be in the correct range
// Postcondition: length and width are set to the given parameters. Length = L, Width = W
LandTract::LandTract(FeetInches l, FeetInches w)
{
	length = l;
	width = w;
}

// Mutators
void LandTract::setLength(FeetInches l)
{
	length = l;
}

void LandTract::setWidth(FeetInches w)
{
	width = w;
}

// Accessors
FeetInches LandTract::getLength() const
{
	return length;
}

FeetInches LandTract::getWidth() const
{
	return width;
}

// Area Calculation
// Precondition: length and width are valid (non negative and non zero)
// Postcondition: returns the area of the land tract as a FeetInches object
FeetInches LandTract::getArea() const
{
	return length.multiply(width); // Uses existing multiply function in FeetInches class to calculate area
}

// Compare Areas
// Precondition: Both objects have valid dimensions
// Postcondition: Returns true if the area are equal
bool LandTract::operator==(const LandTract& right) const
{
	return getArea() == right.getArea(); // Compares the area of the current object with the area of the right object using the overloaded == operator in FeetInches class
}

// Operator+ (Addition of two LandTract objects by adding their areas)
// Precondition: Both objects have valid dimensions
// Postcondition: Returns a new LandTract object with the area of the two added together
LandTract LandTract::operator+(const LandTract& right)
{
	FeetInches newLength = length + right.length; // Adds the lengths of the two LandTract objects using the overloaded + operator in FeetInches class
	FeetInches newWidth = width + right.width; // Adds the widths of the two LandTract objects using the overloaded + operator in FeetInches class
	return LandTract(newLength, newWidth); // Returns a new LandTract object with the new length and width
}

// Assignment Operator Overload (=)
// Precondition: Both LandTract objects have valid dimensions
// Postcondition: Copies the dimensions of the right LandTract object to the left LandTract object
LandTract& LandTract::operator=(const LandTract& right)
{
	if (this != &right)
	{
		length = right.length; // Copies the length of the right object to the left object
		width = right.width; // Copies the width of the right object to the left object
	}
	return *this; // Returns the current object after assignment
}

// Overloaded Output Stream (<<)
// Precondition: LandTract object has valid dimensions
// Postcondition: Returns a formatted output of the LandTract's dimensions and area
ostream& operator<<(ostream& out, const LandTract& tract)
{
	out << "Length: " << tract.length << ", Width: " << tract.width;
	return out;
}

// Prefix Increment Operator (increments length and width) (++)
// Precondition: LandTract object has valid dimensions
// Postcondition: Increments the length and width of the LandTract by 1 inch each and returns the updated object
LandTract& LandTract::operator++()
{
	++length; // Increments the length by 1 inch using the overloaded ++ operator in FeetInches class
	++width; // Increments the width by 1 inch using the overloaded ++ operator in FeetInches class
	return *this; // Returns the updated object
}

// Postfix Increment Operator (increments length and width) (++)
// Precondition: LandTract object has valid dimensions
// Postcondition: Increments the length and width of the LandTract by 1 inch each and returns the original object before incrementing
LandTract LandTract::operator++(int)
{
	LandTract temp = *this; // Creates a temporary object to hold the original state of the current object
	++(*this); // Call prefix increment
	return temp; // Returns the original object before incrementing
}

// Prefix Decrement Operator (decrements length and width) (--)
// Precondition: LandTract object has valid dimensions
// Postcondition: Decrements the length and width of the LandTract by 1 inch each and returns the updated object
LandTract& LandTract::operator--()
{
	--length; // Decrements the length by 1 inch using the overloaded -- operator in FeetInches class
	--width; // Decrements the width by 1 inch using the overloaded -- operator in FeetInches class
	return *this; // Returns the updated object
}

// Postfix Decrement Operator (decrements length and width) (--)
// Precondition: LandTract object has valid dimensions
// Postcondition: Decrements the length and width of the LandTract by 1 inch each and returns the original object before decrementing
LandTract LandTract::operator--(int)
{
	LandTract temp = *this; // Creates a temporary object to hold the original state of the current object
	--(*this); // Call prefix decrement
	return temp; // Returns the original object before decrementing
}