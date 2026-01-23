#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Enter Number: ";
    cin >> Number;

    return Number;
}

string ConvertNumberToText(int Number, string S)
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
            return ConvertNumberToText(stoi(num), S);
        }
    }
    else if (num.length() == 3)
    {
        S += ones[num[0] - '0'] + " hundred ";
        num = num.erase(0, 1);
        return ConvertNumberToText(stoi(num), S);
    }
    else if (num.length() == 4)
    {
        S += ones[num[0] - '0'] + " thousands ";
        num = num.erase(0, 1);
        return ConvertNumberToText(stoi(num), S);
    }
    else if (num.length() == 5)
    {

        sum = (num[0] - '0') * 10 + (num[1] - '0');

        if (sum >= 10 && sum <= 19)
        {
            S += ones[sum] + " thousands ";
            num = num.erase(0, 2);
            return ConvertNumberToText(stoi(num), S);
        }

        S += tens[num[0] - '0'] + " " + ones[num[1] - '0'] + " thousands ";
        num = num.erase(0, 2);
        return ConvertNumberToText(stoi(num), S);
    }

    else if (num.length() == 6)
    {
        S += ones[num[0] - '0'] + " hendrend ";
        num = num.erase(0, 1);
        return ConvertNumberToText(stoi(num), S);
    }
    return S;
}

int main()
{

    int Number = ReadNumber();
    string S = "";
    cout << ConvertNumberToText(Number, S);

    // int Number = 074;
    // string num = to_string(Number);

    // string pp="";
    // pp+="";
    // cout<< pp <<" -";
    // string num="00008";
    // num = num.erase(0, 1);
    // cout<<stoi(num);

    return 0;
}