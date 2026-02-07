#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

string ReadStrinDate()
{
    string Date;
    cout << "\nPlease enter a Date dd/mm/yyyy? ";
    cin >> Date;
    return Date;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> ConvertStringToRecord(string Date, string Separtor)
{
    /*

    // string::npos is technically -1 but "wearing the mask" of an unsigned type (size_t).
    // In Binary, -1 for an unsigned variable is the maximum possible value.
    // Think of a car odometer: if you're at 000,000 and go back 1 mile, it flips to 999,999.
    // We use size_t for 'pos' to avoid overflow if the string is longer than 32,767 (short limit).

     ملاحظة: npos هو حرفياً الرقم -1 لكنه يرتدي قناع الـ unsigned (size_t).
       الخدعة: الرقم -1 في عالم الـ Binary هو نفسه "أقصى قيمة ممكنة" للعداد.
       مثل عداد السيارة: إذا رجعت خطوة واحدة من الصفر، سيعطيك أقصى قراءة 999,999.
       استخدمنا size_t بدلاً من short لضمان عدم حدوث Overflow في النصوص الطويلة.

     size_t pos = 0;

    bm3na fach kyb9a ydbar 3la dak Separtor (pos = Date.find(Separtor)) wmyl9ahch rah kaywsal lwa7d ra9m kbir lihwa (size_t) wkayrdo l -1 wli hya string::npos y3ni ml9ahch

*/

    vector<string> vString;

    size_t pos = 0;

    while ((pos = Date.find(Separtor)) != string::npos)
    {
        vString.push_back(Date.substr(0, pos));

        Date = Date.erase(0, pos + Separtor.length());
    }

    if (Date != "")
    {
        vString.push_back(Date);
    }

    return vString;
}

stDate StringToDate(vector<string> vString)
{
    stDate Date;

    Date.Day = (short)stoi(vString[0]);
    Date.Month = (short)stoi(vString[1]);
    Date.Year = (short)stoi(vString[2]);

    return Date;
}

int main()
{
    string sDate = ReadStrinDate();
    vector vString = ConvertStringToRecord(sDate, "/");

    stDate Date = StringToDate(vString);

    cout << "\n\nDay:" << Date.Day
         << "\nMonth:" << Date.Month << "\nYear:" << Date.Year;

    return 0;
}
