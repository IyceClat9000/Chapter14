// Aleeza Irshad
// 3/31/2026
// Chapter 14
// Collaborators : Angelo, Tanh, Andy, Luis, and Sven.
#include <iostream>
#include "Month.h"
#include "Date.h"
#include "input.h"
using namespace std;

// prototypes
int menuOption();
void Challenge7();
void Challenge8();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0:
            exit(0);
        case 7:
            system("cls");
            Challenge7();
            break;
        case 8:
            system("cls");
            Challenge8();
            break;
        default:
            cout << "\t\tERROR - Invalid option. Please re-enter.\n";
            break;
        }

        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls"); // clear screen

    cout << "\n\tCMPR 121 Chapter 14 Challenges by: Aleeza Irshad, Angelo, Tanh, Andy, Luis, and Sven.";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t 7. Month class";
    cout << "\n\t 8. Date class Modification";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t 0. Quit";
    cout << "\n\t" << string(60, char(205));

    return inputInteger("\n\tOption: ", 0, 8);
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

void Challenge8()
{
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