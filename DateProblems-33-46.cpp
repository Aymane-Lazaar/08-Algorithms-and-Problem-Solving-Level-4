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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

sDate DecreaseDateByXDays(short Days, sDate Date)
{
    for (short i = 0; i < Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    for (short i = 0; i < 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByXWeeks(short Week, sDate Date)
{
    for (short i = 0; i < Week; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{

    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    // last check day in date should not exceed max days in the current month
    // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
    // be 28/2/2022
    
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate DecreaseDateByXMonths(short Months, sDate Date)
{

    for (short i = 0; i < Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{

    Date.Year--;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate DecreaseDateByXYears(short Years, sDate Date)
{

    for (short i = 0; i < Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{

    Date.Year -= Years;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    short Decade = 10;

    Date.Year -= Decade;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate DecreaseDateByXDecades(short Decades, sDate Date)
{

    for (short i = 0; i < Decades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    /*Solution 2
        for (short i = 0; i < Decades; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
    */
    return Date;
}

sDate DecreaseDateByXDecadesFaster(short Decades, sDate Date)
{

    short Decade = 10;

    Date.Year -= Decade * Decades;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
    short Century = 100;

    Date.Year -= Century;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    short Millennium = 1000;

    Date.Year -= Millennium;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
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
    sDate Date1 = ReadFullDate();

    cout << "\nDate After: \n";

    Date1 = DecreaseDateByOneDay(Date1);
    cout << "\n01-Subtracting  one day is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDays(10, Date1);
    cout << "\n02-Subtracting  10 days is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneWeek(Date1);
    cout << "\n03-Subtracting  one week is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXWeeks(10, Date1);
    cout << "\n04-Subtracting  10 weeks is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMonth(Date1);
    cout << "\n05-Subtracting  one month is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXMonths(5, Date1);
    cout << "\n06-Subtracting  5 months is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneYear(Date1);
    cout << "\n07-Subtracting  one year is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYears(10, Date1);
    cout << "\n08-Subtracting  10 Years is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Subtracting  10 Years (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneDecade(Date1);
    cout << "\n10-Subtracting  one Decade is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecades(10, Date1);
    cout << "\n11-Subtracting  10 Decades is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecadesFaster(10, Date1);
    cout << "\n12-Subtracting  10 Decade (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneCentury(Date1);
    cout << "\n13-Subtracting  One Century is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMillennium(Date1);
    cout << "\n14-Subtracting  One Millennium is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    return 0;
}
