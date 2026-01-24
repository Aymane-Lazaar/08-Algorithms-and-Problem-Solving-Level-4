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
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    short Year = ReadYear();

    if (isLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n ";

    return 0;
}
