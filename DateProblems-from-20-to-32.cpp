#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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

struct sDate
{
    short Year;
    short Month;
    short Day;
};

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

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

sDate IncreaseDateByXDays(short Days, sDate Date)
{
    for (short i = 0; i < Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    for (short i = 0; i < 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

sDate IncreaseDateByXWeeks(short Week, sDate Date)
{
    for (short i = 0; i < Week; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
        }
        else
        {
            Date.Month++;
        }

        if (DaysInMonth > NumberOfDaysInAMonth(Date.Month, Date.Year))
        {
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Month++;
    }

    return Date;
}

sDate IncreaseDateByXMonths(int Months, sDate Date)
{

    for (short i = 0; i < Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

int main()
{
    sDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXDays(10, Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneWeek(Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXWeeks(10, Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneMonth(Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXMonths(5, Date);
    cout << "\nDate after adding one day is:"
         << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}
