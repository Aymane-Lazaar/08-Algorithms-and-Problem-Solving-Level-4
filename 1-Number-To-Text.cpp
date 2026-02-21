#include <iostream>
#include <string>

using namespace std;

long long ReadNumber()
{
    long long Number;

    cout << "Enter Number: ";
    cin >> Number;

    return Number;
}

string NumberToText(long long Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"",
                        "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
}

int main()
{

    long long Number = ReadNumber();
    cout << NumberToText(Number);

    return 0;
}

// My Solution
/*
string NumberToText(int Number, string S)
{
    string ones[] = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    string tens[] = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string num = to_string(Number);
    int sum;
    if (Number == 0)
    {

        if (S == "")
        {
            S += ones[num[0] - '0'];
        }

        return S;
    }
    else if (num.length() == 1)
    {
        S += ones[num[0] - '0'];
        return S;
    }
    else if (num.length() == 2)
    {
        sum = (num[0] - '0') * 10 + (num[1] - '0');

        if (sum >= 10 && sum <= 19)
        {
            S += ones[sum];
            num = num.erase(0, 2);
            return S;
        }
        else
        {
            S += tens[num[0] - '0'] + " ";
            num = num.erase(0, 1);
            return NumberToText(stoi(num), S);
        }
    }
    else if (num.length() == 3)
    {
        S += ones[num[0] - '0'] + " hundred ";
        num = num.erase(0, 1);
        return NumberToText(stoi(num), S);
    }
    else if (num.length() == 4)
    {
        S += ones[num[0] - '0'] + " thousands ";
        num = num.erase(0, 1);
        return NumberToText(stoi(num), S);
    }
    else if (num.length() == 5)
    {

        sum = (num[0] - '0') * 10 + (num[1] - '0');

        if (sum >= 10 && sum <= 19)
        {
            S += ones[sum] + " thousands ";
            num = num.erase(0, 2);
            return NumberToText(stoi(num), S);
        }

        S += tens[num[0] - '0'] + " " + ones[num[1] - '0'] + " thousands ";
        num = num.erase(0, 2);
        return NumberToText(stoi(num), S);
    }

    else if (num.length() == 6)
    {
        S += ones[num[0] - '0'] + " hendrend ";
        num = num.erase(0, 1);
        return NumberToText(stoi(num), S);
    }
    return S;
}

int main()
{

    int Number = ReadNumber();
    string S = "";
    cout << NumberToText(Number, S);

    // int Number = 074;
    // string num = to_string(Number);

    // string pp="";
    // pp+="";
    // cout<< pp <<" -";
    // string num="00008";
    // num = num.erase(0, 1);
    // cout<<stoi(num);

    // string ones[] = {
    //     "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    //     "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    // string stnumber = "56464";

    // cout<<ones[int(stnumber[1]-48)];
    // cout<<int('6'-48);

    return 0;
}
    */


