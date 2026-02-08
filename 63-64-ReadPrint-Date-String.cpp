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

vector<string> SplitString(string S1, string Delim)
{

    /*

    /* SUMMARY (خلاصة المنطق):

   1. عندما تفشل دالة find() في العثور على النص، فإنها تعيد القيمة -1.

   2. قاعدة: الـ size_t هو وعاء لا يستوعب إشارة السالب. إذا حاولت تخزين -1 فيه،
      فإنه "يلتف" حول نفسه ليبدأ من أقصى قيمة ممكنة للنظام (Wrap-around).
      لهذا السبب npos (الذي هو -1) يظهر كرقم ضخم جداً.

   3. مثال "خدعة الالتفاف": تخيل أن الـ size_t هو عداد مثل عداد المسافات في السيارة،
      يبدأ من 000 وينتهي عند 999. إذا كان العداد عند 000 وقررت أن ترجع للخلف
      خطوة واحدة (-1)، سيلتف العداد فوراً ليصل إلى 999 (أكبر رقم ممكن).

   4. هذه القيمة القصوى (التي تساوي ~18 كوينتيليون) هي بالضبط std::string::npos.


    //  كيف تعمل find خلف الكواليس؟
    //     عندما تبحث الدالة عن الفاصل في نص طوله 15 حرفاً:
    //     تبدأ من الموقع 0 وتفحص حتى الموقع 14.
    //     إذا وصلت للنهاية ولم تجد شيئاً، لا تقوم بزيادة العداد ليصبح 16، 17... وهكذا.
    //     بدلاً من ذلك، هي مصممة برمجياً لتقفز فوراً إلى القيمة المتفق عليها للفشل، وهي npos.


    // if lenght of word 15 ghadi tstoka 18 كوينتيليون f pos
    //ماذا يحدث في كودك (الـ 15 حرفاً)؟
    // بما أن pos من نوع size_t:
    // في اللحظة التي لا تجد فيها find الفاصل، سيتم تخزين رقم الـ 18 كوينتيليون (القيمة العظمى) داخل pos.
    // في سطر الـ while يتم التحقق: "هل pos (الرقم الضخم) لا يساوي string::npos (الرقم الضخم)؟"
    // النتيجة ستكون False فوراً، وتخرج من الحلقة.



    لو كتبت short pos: سيتخزن فيه -1.

    لو كتبت size_t pos: سيتخزن فيه 18,446,744,073,709,551,615


    - Technically: npos = -1.
    - Practically: Since size_t is unsigned, -1 wraps around to the Maximum Value (~18 Quintillion).
    - In Memory: Both -1 and MaxValue share the exact same binary pattern (all 1s).
    - Logic: When find() fails, it returns this "Max Value" immediately to signal "Not Found".




    bm3na fach kyb9a ydbar 3la dak Separtor (pos = Date.find(Separtor)) wmyl9ahch rah kaywsal lwa7d ra9m kbir lihwa (size_t) lihia nfsah -1 wli hya string::npos y3ni ml9ahch

*/

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

string DateToString(stDate Date)
{
    return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
}

string ReadStringDate(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(DateString);

    cout << "\nDay:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << endl;

    cout << "\n\nYou Enterd:" << DateToString(Date) << "\n";

    return 0;
}
