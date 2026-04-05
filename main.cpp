//Thanh Phan
//04-03-2026
//Chapter 14 - Assignments
#include<iostream>
#include<iomanip>
#include"input.h"
#include"Month.h"


//function prototypes
int menuOption();
void Challenge7();



int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 7: Challenge7(); break;
        //case 8: Challenge8(); break;
        //case 9: Challenge9(); break;
        //case 11: Challenge11(); break;
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
    cout << "\n\tChapter 14 - Assignment by Thanh Phan (04-04-2026)";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t7. Month Class";
    cout << "\n\t8. Date Class Modification";
    cout << "\n\t9. FeetInches Modification";
    cout << "\n\t11. FeetInches Class Copy Constructor and multiply Function";
    cout << "\n\t12. LandTract Class";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Terminate program";
    cout << "\n\t" << string(80, char(205));
    int option = inputInteger("\n\tOption: ", 0, 12);
    return option;
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