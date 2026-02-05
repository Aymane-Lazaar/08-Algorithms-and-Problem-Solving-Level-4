#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct stDate
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

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    return arrDayNames[DayOfWeekOrder];
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

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    // Weekends are Sat and Sun
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 6 || DayIndex == 0);
}

bool IsBusinessDay(stDate Date)
{
    // Solution 1
    //  short DayIndex = DayOfWeekOrder(Date);
    //  return (DayIndex != 6 && DayIndex != 0);

    // Solution 2
    // short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    // return (DayIndex >= 1 && DayIndex <= 5);

    // Solution 3
    return !IsWeekEnd(Date);
    
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    // Solution 1
    //  short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    //  if (Date.Day < DaysInMonth)
    //      return DaysInMonth - Date.Day + 1;

    // Solution 2

    stDate EndMonatDate;
    EndMonatDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndMonatDate.Month = Date.Month;
    EndMonatDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndMonatDate, true);

    return 0;
}

short DaysUntilTheEndOfYear(stDate Date)
{
    /* Solution 1
        short Days = 0;

        while (Date.Day != 31 || Date.Month != 12)
        {
            Days++;
            Date = IncreaseDateByOneDay(Date);
        }

        return ++Days;
    */

    // Solution 2

    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfYearDate, true);
}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);

    tm *now = localtime(&t);

    Date.Day = now->tm_mday;
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;

    // Date.Day = 31;
    // Date.Year = 2022;
    // Date.Month = 12;

    return Date;
}

int main()
{

    stDate Date1 = GetSystemDate();

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1))
         << " , "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    //---------------------
    cout << "\nIs it End of Week?\n";
    if (IsEndOfWeek(Date1))
        cout << "Yes it is Saturday, it's of Week.";
    else
        cout << "No it's Not end of week.";

    //---------------------
    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(Date1))
        cout << "Yes it is a week end.";
    else
        cout << "No today is " << DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";

    //---------------------
    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(Date1))
        cout << "Yes it is a business day.";
    else
        cout << "No it is NOT a business day.";

    //---------------------
    cout << "\n\nDays until end of week : "
         << DaysUntilTheEndOfWeek(Date1) << " Day(s).";

    //---------------------
    cout << "\nDays until end of month : "
         << DaysUntilTheEndOfMonth(Date1) << " Day(s).";

    //---------------------
    cout << "\nDays until end of year : "
         << DaysUntilTheEndOfYear(Date1) << " Day(s).";

    return 0;
}
