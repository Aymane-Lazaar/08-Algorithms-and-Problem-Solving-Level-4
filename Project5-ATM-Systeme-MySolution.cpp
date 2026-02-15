#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenue();
void ShowQuickWithdrawMenu();
void Login();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

sClient CurrentClient;

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

vector<sClient> LoadCleintsDataFromFile(string FileName)
{

    vector<sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient &CurrentClient)
{

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient &C : vClients)
    {

        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            CurrentClient = C;
            return true;
        }
    }
    return false;
}

bool LoadClientInfo(string Username, string Password)
{
    return FindClientByAccountNumberAndPinCode(Username, Password, CurrentClient);
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToShowQuickWithdrawMenu()
{
    cout << "\n\nPress any key to continue...";
    system("pause>0");
    ShowQuickWithdrawMenu();
}

enum enMainMenueOptions
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5,
};

short ReadQuickWithdrawMenu()
{
    cout << "Choose what do you want to do? [1 to 8]? \n";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

enum enQuickWithdrawMenuOptions
{
    eWithdraw20 = 1,
    eWithdraw50 = 2,
    eWithdraw100 = 3,
    eWithdraw200 = 4,
    eWithdraw400 = 5,
    eWithdraw600 = 6,
    eWithdraw800 = 7,
    eWithdraw1000 = 8,
};

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient &C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                // we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> &vClients)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }
        }

        return false;
    }
    return false;
}

void Withdraw(short Amount)
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    char Answer = 'n';
    if (Amount > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance ,make another choice";
        GoBackToShowQuickWithdrawMenu();
        return;
    }

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount * -1, vClients);
}

void PerfromQuickWithdrawMenu(enQuickWithdrawMenuOptions QuickWithdrawMenu)
{
    switch (QuickWithdrawMenu)
    {
    case enQuickWithdrawMenuOptions::eWithdraw20:
        system("cls");
        Withdraw(20);
        GoBackToMainMenue();
        break;

    default:
        break;
    }
}

void ShowQuickWithdrawMenu()
{
    cout << "===================================\n";
    cout << "\tQuick Withdraw Menu\n";
    cout << "===================================\n";

    cout << "\t[1] 20\t" << "[2] 50\n";
    cout << "\t[3] 100\t" << "[4] 200\n";
    cout << "\t[5] 400\t" << "[6] 600\n";
    cout << "\t[7] 800\t" << "[8] 1000\n";
    cout << "\t[9] Exit\t";
    cout << "\n===================================\n";

    cout << "\nYour Balance is " << CurrentClient.AccountBalance;
    PerfromQuickWithdrawMenu((enQuickWithdrawMenuOptions)ReadQuickWithdrawMenu());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{

    switch (MainMenueOption)
    {
    case enMainMenueOptions::eQuickWithdraw:
    {
        system("cls");
        ShowQuickWithdrawMenu();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eLogout:
        system("cls");
        Login();
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void Login()
{

    string AccountNumber, PinCode;

    bool LoginFaild = false;

    do
    {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
            cout << "Invlaid Account Number/PinCode!\n";

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    Login();

    return 0;

}
