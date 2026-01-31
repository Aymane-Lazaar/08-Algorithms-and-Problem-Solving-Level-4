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

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{

    // if (Date1.Year < Date2.Year)
    // {
    //     return true;
    // }
    // else if (Date1.Year == Date2.Year)
    // {
    //     if (Date1.Month < Date2.Month)
    //     {
    //         return true;
    //     }
    //     else if (Date1.Month == Date2.Month)
    //     {
    //         if (Date1.Day < Date2.Day)
    //         {
    //             return true;
    //         }
    //     }
    // }

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
    stDate Date1 = ReadFullDate();

    stDate Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is Less than Date2.";
    else
        cout << "\nNo, Date1 is NOT Less than Date2.";

    return 0;
}
