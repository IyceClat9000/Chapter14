// Angelo Manzano
// 3/31/2026
// Chapter 14
// Collaborators : Tanh, Andy, Luis, Aleeza, and Sven.
#include<iostream>
#include "Month.h"
#include "FeetInches.h"
#include "input.h"
using namespace std;

// prototypes

int menuOption();
void Challenge7();
void Challenge9();
void Challenge11();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 7: Challenge7(); break;
            //case 8: Challenge8(); break;
        case 9: Challenge9(); break;
        case 11: Challenge11(); break;
            //case 12: Challenge12(); break;
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
	cout << "\n\tCMPR 121 Chapter 14 Challenges by: Angelo Manzano, Tanh, Andy, Luis, Aleeza, and Sven.";
	cout << "\n\t" + string(80, char(205));
    cout << "\n\t7. Month Class";
    cout << "\n\t11. FeetInches Class Copy Constructor and multiply Function.";
	cout << "\n\t9. FeetInches Class Relational Operators.";
    cout << "\n\t" + string(80, char(196));
	cout << "\n\t0. Exit Program.";
    cout << "\n\t" + string(80, char(205));
    return inputInteger("\n\tOption: ", 0, 12);
}

void Challenge7()
{
    Month testMonth1;

    cout << testMonth1 << "\n";

    Month testMonth2(10);

    cout << testMonth2 << "\n";

    Month testMonth3;

    testMonth3.setName(inputString("\n\tEnter the month name: ", false));

    cout << ++testMonth3 << "\n";

    cout << testMonth3++ << "\n";

    cout << testMonth3 << "\n";

    cout << --testMonth3 << "\n";

    cout << testMonth3-- << "\n";

    cout << testMonth3 << "\n";
}

void Challenge9()
{
	//Testing the overloaded <=, >=, and != operators
    FeetInches compare1(5, 4);
    FeetInches compare2(5, 6);
    FeetInches compare3(3, 4);
    FeetInches compare4(5, 4);
    FeetInches compare5(5, 3);

    cout << "\n\tHere is the objects we will compare.";
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
