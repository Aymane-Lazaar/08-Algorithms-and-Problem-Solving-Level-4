#include <iostream>
#include <string>

using namespace std;

// Leap Year=All years which are perfectly divisible by 4 are leap years except for century years (years ending with 00), which are leap years only if they are perfectly divisible by 400.

short ReadYear()
{
    short Year;

    cout << "Enter Number: ";
    cin >> Year;

    return Year;
}

bool isLeapYear(short Year)
{

    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }

    return false;
}

// My Solution
/*
bool IsLeapYear(int Year)
{
    if (Year % 100 == 0 && (Year / 400) == Year / 400.0)
    {
        return true;
    }
    else if (Year / 4 == Year / 4.0 && Year % 100 != 0)
    {
        return true;
    }

    return false;
}
*/

int main()
{
    short Year = ReadYear();

    if (isLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n ";

    return 0;
}
