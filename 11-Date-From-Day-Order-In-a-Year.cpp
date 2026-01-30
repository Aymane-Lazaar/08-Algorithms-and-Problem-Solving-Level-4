#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(short Year)
{
    // في الجزء الثاني من الكود لديك: (Year % 100 == 0 && Year % 400 == 0) رياضياً، أي رقم يقبل القسمة على 400 فهو بالضرورة يقبل القسمة على 100.

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
}

struct sDate
{
    short Year;
    short Month;
    short Day;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (RemainingDays > MonthDays)
        {
            // bach kan7sbo total days kanrido bchhar 9bal same thing bach n9so karydo chhar 9bal wky3tina ch7al b9a mn nhar 7itach ana aslan dak nhar lidkhlto rani kanzido 7ta ltali

            RemainingDays -= MonthDays; // Subtract the number of days in the current month from the remaining day count,
            Date.Month++;               // moving the calculation forward to the next month
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    short DaysOrderInYear =
        NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

    cout << "\nNumber of Days from the begining of the year is "
         << DaysOrderInYear << "\n\n";

    sDate Date;
    Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
    cout << "Date for [" << DaysOrderInYear << "] is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}
