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
    // في الجزء الثاني من الكود لديك: (Year % 100 == 0 && Year % 400 == 0) رياضياً، أي رقم يقبل القسمة على 400 فهو بالضرورة يقبل القسمة على 100.

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();
    cout << "\nNumber of Days in Year [" << Year << "] is "
         << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours in Year [" << Year << "] is "
         << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is "
         << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is "
         << NumberOfSecondsInAYear(Year);

    return 0;
}
