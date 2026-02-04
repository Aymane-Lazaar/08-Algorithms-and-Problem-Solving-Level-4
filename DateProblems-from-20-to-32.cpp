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
    // Solution 1

    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    // last check day in date should not exceed max days in the current month
    //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    //  be 28/2/2022
    
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;

    /*Solution 2
    short NumberOfDaysInCurrentMonth  = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

            //last check day in date should not exceed max days in the current month
            // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
            // be 28/2/2022

        if (NumberOfDaysInCurrentMonth  > NumberOfDaysInAMonth(Date.Month, Date.Year))
        {
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Month++;
    }

    return Date;
    */
}

sDate IncreaseDateByXMonths(short Months, sDate Date)
{

    for (short i = 0; i < Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{

    Date.Year++;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate IncreaseDateByXYears(short Years, sDate Date)
{

    for (short i = 0; i < Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
{

    Date.Year += Years;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
    short Decade = 10;

    Date.Year += Decade;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate IncreaseDateByXDecades(short Decades, sDate Date)
{

    for (short i = 0; i < Decades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    /*Solution 2
        for (short i = 0; i < Decades; i++)
        {
            Date = IncreaseDateByOneDecade(Date);
        }
    */
    return Date;
}

sDate IncreaseDateByXDecadesFaster(short Decades, sDate Date)
{

    short Decade = 10;

    Date.Year += Decade * Decades;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
    short Century = 100;

    Date.Year += Century;

    if (!isLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Day = 28;
    }

    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
    short Millennium = 1000;

    Date.Year += Millennium;

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

    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\n01-Adding one day is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "\n02-Adding 10 days is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneWeek(Date1);
    cout << "\n03-Adding one week is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXWeeks(10, Date1);
    cout << "\n04-Adding 10 weeks is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMonth(Date1);
    cout << "\n05-Adding one month is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXMonths(5, Date1);
    cout << "\n06-Adding 5 months is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYears(10, Date1);
    cout << "\n08-Adding 10 Years is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Adding 10 Years (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "\n10-Adding one Decade is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1);
    cout << "\n11-Adding 10 Decades is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecadesFaster(10, Date1);
    cout << "\n12-Adding 10 Decade (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "\n13-Adding One Century is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "\n14-Adding One Millennium is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    return 0;
}
