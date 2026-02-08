#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadStringDate(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    size_t pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vString = SplitString(DateString, "/");

    Date.Day = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);

    return Date;
}

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);

    while (pos != string::npos)
    {
        S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace); // find next
    }

    return S1;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(DateFormat, "yyyy", to_string(Date.Year));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));

    return FormattedDateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(DateString);

    cout << "\n\n"
         << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n\n"
         << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n\n"
         << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n\n"
         << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n\n";

    cout << "\n\n"
         << FormatDate(Date, "Day:dd, Month:mm,  Day:yyyy") << "\n";

    return 0;
}
