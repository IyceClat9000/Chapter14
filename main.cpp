// Thanh Phan
// 3/31/2026
// Chapter 14 - Assignment
// Group members : Angelo Manzano, Thanh, Andy, Luis, Aleeza, and Sven.
#include<iostream>
#include "Month.h"
#include "Date.h"
#include "FeetInches.h"
#include "LandTract.h"
#include "input.h"
using namespace std;

// prototypes

int menuOption();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge11();
void Challenge12();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 9: Challenge9(); break;
        case 11: Challenge11(); break;
        case 12: Challenge12(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;

}


int menuOption()
{
    system("cls");
    cout << "\n\tChapter 14 - Assignment";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t7. Month Class";
    cout << "\n\t8. Date Class Modification";
    cout << "\n\t9. FeetInches Modification";
    cout << "\n\t11. FeetInches Class Copy Constructor and multiply Function";
    cout << "\n\t12. LandTract Class";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Terminate program";
    cout << "\n\t" << string(80, char(205));
    return inputInteger("\n\tOption: ", 0, 12);
}

void Challenge7()
{
    system("cls");
    cout << "\n\t7. Month class";
    cout << "\n\t" << string(80, char(196));

    cout << "\n\tTesting default constructor, instance m1:";
    Month m1;
    cout << "\n\tm1: " << m1; // also test the overloaded stream operator here

    cout << "\n\tTesting argument constructor, instance m2 (pass in 8): ";
    Month m2(8);
    cout << "\n\tm2: " << m2;

    cout << "\n\tTesting copy constructor, copy m2 to m3";
    Month m3(m2);
    cout << "\n\tm3: " << m3;

    m3.setName(inputString("\n\tEnter the name for m3 (abriviation, first 3 letters of the month): ", false));
    cout << "\n\tm3: " << m3 << "\n";

    cout << "\n\tTesting assignment operator: assign m2 to m1";
    m1 = m2;
    cout << "\n\tm1 now: " << m1;

    cout << "\n\n\tTesting prefix++ on m1: ";
    cout << "\n\tBefore: " << m1;
    cout << "\n\tReturned value: " << ++m1;
    cout << "\n\tAfter: " << m1;

    cout << "\n\n\tTesting postfix++ on m1: ";
    cout << "\n\tBefore: " << m1;
    cout << "\n\tReturned value: " << m1++;
    cout << "\n\tAfter: " << m1;

    cout << "\n\n\tTesting prefix-- on m2: ";
    cout << "\n\tBefore: " << m2;
    cout << "\n\tReturned value: " << --m2;
    cout << "\n\tAfter: " << m2;

    cout << "\n\n\tTesting postfix-- on m2: ";
    cout << "\n\tBefore: " << m2;
    cout << "\n\tReturned value: " << m2--;
    cout << "\n\tAfter: " << m2;

    Month m4(1);
    cout << "\n\tUsing m4 to test addition and subtraction operator: ";
    cout << "\n\tm4: " << m4;
    cout << "\n\tm4 + 5: ";
    cout << m4 + 5;
    cout << "\n\tm4 - 7: ";
    cout << m4 - 7;
}

void Challenge8()
{
    system("cls");
    cout << "\n\t8. Date Class Modification";
    cout << "\n\t" << string(80, char(196));

    Date D1, D2;

    cout << "\nEnter new date values for D1";
    cin >> D1;

    cout << "\n\nD1 = " << D1 << "\n";

    cout << "\nD1++ = " << D1++ << "\n";
    cout << "\n++D1 = " << ++D1 << "\n";

    cout << "\nEnter new date values for D1";
    cin >> D1;

    cout << "\n\nD1-- = " << D1-- << "\n";
    cout << "\n--D1 = " << --D1 << "\n";

    cout << "\nEnter new date values for D1";
    cin >> D1;

    cout << "\nEnter new date values for D2";
    cin >> D2;

    cout << "\nD1 - D2 = " << (D1 - D2) << "\n";
}

void Challenge9()
{
    system("cls");
    cout << "\n\t9. FeetInches Modification";
    cout << "\n\t" << string(80, char(196));
    //Testing the overloaded <=, >=, and != operators
    FeetInches compare1(5, 4);
    FeetInches compare2(5, 6);
    FeetInches compare3(3, 4);
    FeetInches compare4(5, 4);
    FeetInches compare5(5, 3);

    cout << "\n\tHere are the objects we will compare.";
    cout << "\n\n\tCompare 1: " << compare1 << "\n\n";
    cout << "\n\tCompare 2:" << compare2 << "\n\n";
    cout << "\n\tCompare 2 is ";
    if (!(compare2 <= compare1))
        cout << "NOT ";
    cout << "less than or equal to Compare 1.";
    cout << "\n\tCompare 2 is ";
    if (!(compare2 >= compare1))
        cout << "NOT ";
    cout << "greater than or equal to Compare 1.";
    cout << "\n\tCompare 2 is ";
    if (!(compare2 != compare1))
        cout << "NOT ";
    cout << "not equal to Compare 1.";
    cout << "\n\n";
}

void Challenge11()
{
    system("cls");
    cout << "\n\t11. FeetInches Copy Constructor and multiply Function";
    cout << "\n\t" << string(80, char(196));
    //A lot of these also use the overloaded output operator so its getting tested everywhere
    //Testing the default, argument, and copy constructors, with the overloaded assignment operator
    FeetInches measurement;
    cout << "\n\tShowing the default constructor. ";
    cout << measurement << "\n\t";

    FeetInches measurement2(12, 1);
    cout << "\n\tShowing the argument constructor with 12 feet and 1 inch.";
    cout << measurement2 << "\n\t";

    FeetInches measurement3(measurement2);
    cout << "\n\tShowing the copy constructor that will copy the object previous to it.";
    cout << measurement3 << "\n\t";
    cout << "\n\tShowing the same object using the overloaded = operator to become the 1st object.";
    measurement3 = measurement;
    cout << measurement3;
    cout << "\n\t";
    //Testing the multiply function
    FeetInches multiply1(2, 4);
    FeetInches multiply2(3, 6);
    FeetInches result(multiply1.multiply(multiply2));
    cout << "\n\tShowing the multiply function that will multiply one object (2 feet and 4 inches) with another (3 feet and 6 inches).";
    cout << result << "\n\t";
    cout << "\n\tThe following will be a lot of lines to show the increment operators. Be sure to continue after reading all that was before.\n\t";
    system("pause");
    system("cls");
    //Testing the incrementing overloaded operators, postfix and prefix
    cout << "\n\tHere is the beginning measurement incremented 6 times with prefix incrementing.\n\t";

    for (int i = 0; i < 6; i++)
    {
        cout << "\n\tIncrement with prefix # " << i + 1 << ": ";
        cout << ++measurement;
    }
    cout << "\n\tHere is the same measurement incremented 6 times. with postfix and a second cout to show its increment.\n\t";
    for (int i = 0; i < 6; i++)
    {
        cout << "\n\tIncrement with postfix # " << i + 1 << ": ";
        cout << measurement++;
        cout << "\n\tActual increment in the object: ";
        cout << measurement;
        cout << "\n\t";
    }

    cout << "\n\tThe following will be a lot of lines to show the decrement operators. Be sure to continue after reading all that was before.\n\t";
    system("pause");
    system("cls");
    //Testing the decrementing overloaded operators, postfix and prefix
    cout << "\n\tHere is the beginning measurement decremented 6 times with prefix decrementing.\n\t";

    for (int i = 0; i < 6; i++)
    {
        cout << "\n\tDecrement with prefix # " << i + 1 << ": ";
        cout << --measurement;
    }
    cout << "\n\tHere is the same measurement decremented 6 times. with postfix and a second cout to show its decrement.\n\t";
    for (int i = 0; i < 6; i++)
    {
        cout << "\n\tDecrement with postfix # " << i + 1 << ": ";
        cout << measurement--;
        cout << "\n\tActual decrement in the object: ";
        cout << measurement;
        cout << "\n\t";
    }
    cout << "\n\tThe following show the relational < and == overloaded operators, when you have read all before you may continue.\n\t";
    system("pause");
    system("cls");
    //Testing the overloaded == and < operators
    FeetInches compare1(5, 4);
    FeetInches compare2(5, 6);
    FeetInches compare3(3, 4);
    FeetInches compare4(5, 4);
    FeetInches compare5(5, 3);
    cout << "\n\tHere is the objects we will compare.";
    cout << "\n\tCompare 1:";
    cout << compare1;
    cout << "\n\n";
    cout << "\n\tCompare 2:";
    cout << compare2;
    cout << "\n\tCompare 2 is ";
    if (!(compare2 < compare1))
        cout << "NOT ";
    cout << "less than Compare 1.";
    cout << "\n\tCompare 2 is ";
    if (!(compare2 == compare1))
        cout << "NOT ";
    cout << "equal to Compare 1.";

    cout << "\n\tCompare 3:";
    cout << compare3;
    cout << "\n\tCompare 3 is ";
    if (!(compare3 < compare1))
        cout << "NOT ";
    cout << "less than Compare 1.";
    cout << "\n\tCompare 3 is ";
    if (!(compare3 == compare1))
        cout << "NOT ";
    cout << "equal to Compare 1.";
    cout << "\n\tCompare 4:";
    cout << compare4;
    cout << "\n\tCompare 4 is ";
    if (!(compare4 < compare1))
        cout << "NOT ";
    cout << "less than Compare 1.";
    cout << "\n\tCompare 4 is ";
    if (!(compare4 == compare1))
        cout << "NOT ";
    cout << "equal to Compare 1.";
    cout << "\n\tCompare 5:";
    cout << compare5;
    cout << "\n\tCompare 5 is ";
    if (!(compare5 < compare1))
        cout << "NOT ";
    cout << "less than Compare 1.";
    cout << "\n\tCompare 5 is ";
    if (!(compare5 == compare1))
        cout << "NOT ";
    cout << "equal to Compare 1.";
    cout << "\n\tThe final section will show the addition and subtraction operators, when you have read all before you may continue.\n\t";
    system("pause");
    system("cls");
    //Testing the overloaded addition and subtraction operators
    cout << "\n\tCompare 1:";
    cout << compare1;
    cout << "\n\tCompare 2:";
    cout << compare2;
    cout << "\n\tCompare 3:";
    cout << compare3;
    cout << "\n\tCompare 4:";
    cout << compare4;
    cout << "\n\n\tSubtraction:";
    cout << "\n\tCompare 1 - Compare 2.";
    cout << (compare1 - compare2);
    cout << "\n\tCompare 1 - Compare 3.";
    cout << (compare1 - compare3);
    cout << "\n\tCompare 1 - Compare 4.";
    cout << (compare1 - compare4);

    cout << "\n\n\tAddition:";
    cout << "\n\tCompare 1 + Compare 2.";
    cout << (compare1 + compare2);
    cout << "\n\tCompare 1 + Compare 3.";
    cout << (compare1 + compare3);
    cout << "\n\tCompare 1 + Compare 4.";
    cout << (compare1 + compare4);
}

void Challenge12()
{
    system("cls");
    cout << "\n\t12. LandTract Class";
    cout << "\n\t" << string(80, char(196));

    FeetInches length1, width1, length2, width2;
    int feet, inches;

    // ---------- Input for Tract 1-----------
    cout << "\n\n\tEnter dimensions for Tract 1";

    cout << "\nLength:";
    cout << "\n\tFeet: ";
    cin >> feet;
    cout << "\tInches: ";
    cin >> inches;
    length1 = FeetInches(feet, inches);

    cout << "Width";
    cout << "\n\tFeet: ";
    cin >> feet;
    cout << "\tInches: ";
    cin >> inches;
    width1 = FeetInches(feet, inches);

    // ---------- Input for Tract 2-----------
    cout << "\n\n\tEnter dimensions for Tract 2";

    cout << "\nLength:";
    cout << "\n\tFeet: ";
    cin >> feet;
    cout << "\tInches: ";
    cin >> inches;
    length2 = FeetInches(feet, inches);

    cout << "Width";
    cout << "\n\tFeet: ";
    cin >> feet;
    cout << "\tInches: ";
    cin >> inches;
    width2 = FeetInches(feet, inches);


    // ---------- Create LandTract Objects -----------
    LandTract tract1(length1, width1);
    LandTract tract2(length2, width2);

    cout << "\n\n\tCreating two LandTract objects using the dimensions entered...";

    // ----- Output Area -----
    FeetInches area1 = tract1.getArea();
    cout << "\n\nThe area of LT1 = "
        << area1.getFeet() << " feet, " << area1.getInches() << " inches";

    FeetInches area2 = tract2.getArea();
    cout << "\n\nThe area of LT2 = "
        << area2.getFeet() << " feet, " << area2.getInches() << " inches";

    // ----- Compare Areas -----
    cout << "\n\n\tComparing the area of the two tracts...";

    if (tract1 == tract2)
        cout << "\n\tThe two tracts are the same size.";
    else
        cout << "\n\tThe two tracts do NOT have the same area.";

    cout << "\n";
}