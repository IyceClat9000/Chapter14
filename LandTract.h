#pragma once
#ifndef LANDTRACT_H
#define LANDTRACT_H

#include "FeetInches.h"

class LandTract
{
private:
	FeetInches length;
	FeetInches width;

public:
	// Constructors
	// Precondition: None
	// Postcondition: length and width are set to 0 feet and 0 inches
	LandTract();

	// Constructors
	// Precondition: l and w should be defined objects with positive feet and inches, inches should be in the range 1-12
	// Postcondition: length and width are set to the given parameters. Length = L, Width = W
	LandTract(FeetInches l, FeetInches w);

	// Mutators
	void setLength(FeetInches l);
	void setWidth(FeetInches w);

	// Accessors
	FeetInches getLength() const;
	FeetInches getWidth() const;

	// getArea Function
	// Precondition: length and width are valid
	// Postcondition: returns the area of the land tract as a FeetInches object
	FeetInches getArea() const;

	// Operator==
    // Precondition: Both objects have valid dimensions
    // Postcondition: Returns true if the area are equal
	bool operator ==(const LandTract& right) const;
};

#endif
