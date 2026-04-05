#include "LandTract.h"

// Default Constructor
LandTract::LandTract()
{
	length = FeetInches(0, 0);
	width = FeetInches(0, 0);
}

// Argument Constructor
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
FeetInches LandTract::getArea() const
{
	return length.multiply(width); // Uses existing multiply function in FeetInches class to calculate area
}

// Compare Areas
bool LandTract::operator==(const LandTract& right) const
{
	return getArea() == right.getArea(); // Compares the area of the current object with the area of the right object using the overloaded == operator in FeetInches class
} 
