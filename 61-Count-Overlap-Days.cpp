#include <iostream>
#include <string>

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

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
    // Solution 1
    //  return !IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) && !IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate);

    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    {
        return true;
    }
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{

    return !(
        CompareDates(Date, Period.StartDate) == enDateCompare::Before ||
        CompareDates(Date, Period.EndDate) == enDateCompare::After

    );
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    if (IsOverLapPeriods(Period1, Period2))
    {
        if (IsDateInPeriod(Period2.StartDate, Period1))
        {
            return Period1.EndDate.Day - Period2.StartDate.Day;
        }
        else if (IsDateInPeriod(Period2.EndDate, Period1))
        {
            return Period2.EndDate.Day - Period2.StartDate.Day;
        }

        else if (IsDateInPeriod(Period1.StartDate, Period2))
        {
            return Period1.EndDate.Day - Period2.StartDate.Day;
        }
        else if (IsDateInPeriod(Period1.EndDate, Period2))
        {
            return Period1.EndDate.Day - Period2.StartDate.Day;
        }
    }

    return 0;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{

    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    // if (IsOverLapPeriods(Period1, Period2))
    //     cout << "Yes, Periods Overlap\n";
    // else
    //     cout << "No, Periods is not Overlap\n";

    cout << "Overlap Days Count Is: " << CountOverlapDays(Period1, Period2);

    return 0;
}