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

void MonthCalender(short Month, short Year)
{
    short NumberOfDays = NumberOfDaysInAMonth(Year, Month);
    cout << "\n\n_______________________" << MonthShortName(Month) << "_______________________\n\n";

    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    short Day = DayOfWeekOrder(1, Month, Year);

    for (short i = 0; i < Day; i++)
    {
        if (i != Day)
        {
            cout << setw(5);
        }
        else
        {
            break;
        }
    }

    

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

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    MonthCalender(Month, Year);

    return 0;
}
