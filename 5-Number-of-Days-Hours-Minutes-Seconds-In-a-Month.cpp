#include <iostream>
#include <string>

using namespace std;

// Leap Year=All years which are perfectly divisible by 4 are leap years except for century years (years ending with 00), which are leap years only if they are perfectly divisible by 400.

bool isLeapYear(short Year)
{
    // في الجزء الثاني من الكود لديك: (Year % 100 == 0 && Year % 400 == 0) رياضياً، أي رقم يقبل القسمة على 400 فهو بالضرورة يقبل القسمة على 100.

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
    {
        return isLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 1; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month)
            return 31;
    }

    // if you reach here then its 30 days.
    return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
    return NumberOfMinutesInAMonth(Year, Month) * 60;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month to check? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days in Year [" << Year << "] is "
         << NumberOfDaysInMonth(Year, Month);

    cout << "\nNumber of Hours in Year [" << Year << "] is "
         << NumberOfHoursInMonth(Year, Month);

    cout << "\nNumber of Minutes in Year [" << Year << "] is "
         << NumberOfMinutesInAMonth(Year, Month);

    cout << "\nNumber of Seconds in Year [" << Year << "] is "
         << NumberOfSecondsInAMonth(Year, Month);

    return 0;
}
