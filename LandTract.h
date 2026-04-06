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

	// Operator + to add two LandTract objects together by adding their areas
	// Precondition: Both objects have valid dimensions
	// Postcondition: Returns a new LandTract object with the area of the two added together
	LandTract operator + (const LandTract& right);

	// Assigment Operator
	// Precondition:Both LandTract objects have valid dimensions
	// Postcondition: Copies the dimensions of the right LandTract object to the left LandTract object
	LandTract& operator = (const LandTract& right);

	// Overloaded outstream operator for LandTract objects
	// Precondition: LandTract object has valid dimensions
	// Postcondition: Returns a formatted output of the LandTract's dimensions and area
	friend ostream& operator << (ostream& out, const LandTract& tract);

	// Prefix increment operator (increments length and width)
	// Precondition: LandTract object has valid dimensions
	// Postcondition: Increments the length and width of the LandTract by 1 inch each and returns the updated object
	LandTract& operator ++();

	// Postfix increment operator (increments length and width)
	// Precondition: LandTract object has valid dimensions
	// Postcondition: Increments the length and width of the LandTract by 1 inch each and returns the original object before incrementing
	LandTract operator ++(int);

	// Prefix decrement operator (decrements length and width)
	// Precondition: LandTract object has valid dimensions
	// Postcondition: Decrements the length and width of the LandTract by 1 inch each and returns the updated object
	LandTract& operator --();

	// Postfix decrement operator (decrements length and width)
	// Precondition: LandTract object has valid dimensions
	// Postcondition: Decrements the length and width of the LandTract by 1 inch each and returns the original object before decrementing
	LandTract operator --(int);

};

#endif
    
