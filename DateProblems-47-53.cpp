#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

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
    short a, y, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);

    tm *now = localtime(&t);

    Date.Day = now->tm_mday;
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;

    return Date;
}

int main()
{

    stDate Date = GetSystemDate();

    return 0;
}