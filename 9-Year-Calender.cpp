#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(short Year)
{
    // في الجزء الثاني من الكود لديك: (Year % 100 == 0 && Year % 400 == 0) رياضياً، أي رقم يقبل القسمة على 400 فهو بالضرورة يقبل القسمة على 100.

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
}

string MonthShortName(short Month)
{
    string MonthsShort[13] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    return MonthsShort[Month];
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder];
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Year, Month);

    // Print the current month name
    printf("\n _______________%s_______________\n\n",
           MonthShortName(Month).c_str());
    /*
            `.c_str()` is a function of the `std::string` class
            Its function is to convert `std::string` to a C-style string (`const char*`).
            This is important if you want to use `printf` or any function that requires `char*`.
    */

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    // Print appropriate spaces

    short i;

    for (i = 0; i < current; i++)
        printf("     ");

    for (short j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j); //%5d in printf means: Print the correct number within a 5-digit field. If the number is shorter, place blank spaces on the left.
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n _________________________________\n");
}

void PrintYearCalendar(short Year)
{
    printf("\n _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf(" _________________________________\n");

    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, Year);
    }
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();

    PrintYearCalendar(Year);

    return 0;
}
