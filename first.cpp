#include <iostream>
using namespace std;
// Customer Class
class Customer
{
public:
    int age;
    string name;
    float balance;
    Customer()
    {
    }

    Customer(int Age, string Name, float Balance)
    {
        age = Age;
        name = Name;
        balance = Balance;
    }
};

class Bank
{

public:
    Customer customers[100];
    string bankName;
    int totalCustomers = 0;

    Bank()
    {
    }

    Bank(string BankName)
    {
        bankName = BankName;
        totalCustomers = 0;
    }

    void AddCustomer()
    {
        int age = 0;
        string name;
        cout << "Enter Your Age \t";
        cin >> age;
        cout << "\n"
             << "Enter Your Name\t";
        cin >> name;
        cout << endl;
        customers[totalCustomers] = Customer(age, name, 0);
        totalCustomers += 1;
    }
    void displayCustomers()
    {
        for (int i = 0; i < totalCustomers; i++)
        {
            cout << "_____________________________________" << endl;
            cout << "Name" << customers[i].name << endl;
            cout << "Age" << customers[i].age << endl;
            cout << "Balance" << customers[i].balance << endl;
            cout << "_____________________________________" << endl;
        }
    }
};

// Functions start here
void DisplayBankDetails(Bank temp)
{
    cout << "---------------------------------------------------" << endl;
    cout << "Name of the bank is " << temp.bankName << endl;
    cout << "Total No of Active Users " << temp.totalCustomers << "\n";
    cout << "---------------------------------------------------" << endl;
}

void RemoveBank(string bname, Bank *banks, int *totalBanksNo)
{
    int temp = -1;

    for (int i = 0; i < *totalBanksNo; i++)
    {
        if (banks[i].bankName == bname)
        {
            temp = i;
            break;
        }
    }
    if (temp != -1)
    {

        banks[temp] = banks[*totalBanksNo - 1];
        *totalBanksNo -= 1;
    }
    else
    {
        cout << "Bank Not Found";
    }
}

void InsertUser(string bname, Bank *banks, int *totalBanksNo)
{
    int temp = -1;

    for (int i = 0; i < *totalBanksNo; i++)
    {
        if (banks[i].bankName == bname)
        {
            temp = i;
            break;
        }
    }
    if (temp != -1)
    {

        banks[temp].AddCustomer();
    }
    else
    {
        cout << "Bank Not Found! Please make sure you enter the correct name";
    }
}
void DisplayAllBanks(Bank *banks, int *totalBanksNo)
{
    cout << "All Banks"
         << "\n";

    for (int i = 0; i < *totalBanksNo; i++)
    {
        DisplayBankDetails(banks[i]);
        cout << endl;
    }
}

void DisplayBanksCustomers(string bname, Bank *banks, int *totalBanksNo)
{
    int temp = -1;

    for (int i = 0; i < *totalBanksNo; i++)
    {
        if (banks[i].bankName == bname)
        {
            temp = i;
            break;
        }
    }
    if (temp != -1)
    {

        Bank tempCount = banks[temp];
        tempCount.displayCustomers();
    }
    else
    {
        cout << "Bank Not Found! Please make sure you enter the correct name";
    }
}

void Admin(Bank *banks, int *totalBanksNo)
{
    int userInput, temp;
    string removeName;
    bool boolVar = true;
    while (boolVar)
    {
        cout << "1) Register New Bank" << endl;
        cout << "2) Remove Bank" << endl;
        cout << "3) Show all Customers of a  Bank" << endl;
        cout << "4) Exit" << endl;
        cin >> userInput;

        switch (userInput)
        {
            // 1 register
            //2 remove
            //3 show all customers of a bank
        case 1:
            cout << "Enter bank name\n";
            cin >> removeName;
            banks[*totalBanksNo] = Bank(removeName);
            DisplayBankDetails(banks[*totalBanksNo]);
            *totalBanksNo += 1;
            DisplayAllBanks(banks, totalBanksNo);
            break;
        case 2:

            cout << "\n"
                 << "Enter Name of bank you want to delete\n";
            cin >> removeName;
            cout << endl;
            RemoveBank(removeName, banks, totalBanksNo);
            DisplayAllBanks(banks, totalBanksNo);
            break;
        case 3:

            cout << "\n"
                 << "Enter Name of bank you want to show customers\n";
            cin >> removeName;
            cout << endl;
            DisplayBanksCustomers(removeName, banks, totalBanksNo);

            break;
        case 4:
            boolVar = false;
            break;
        default:
            cout << "Incorrect Input,Please Try again";
        }
    }
}

void User(Bank *banks, int *totalBanksNo)
{

    int userInput = 1;
    string bname;
    //1 Register
    bool boolVar = true;
    while (boolVar)
    {
        cout << "1) Create Account" << endl;
        cout << "2) Exit" << endl;
        cin >> userInput;
        switch (userInput)
        {
        case 1:

            DisplayAllBanks(banks, totalBanksNo);
            cout << "Enter the name of a bank you want to create an account in" << endl;
            cin >> bname;
            InsertUser(bname, banks, totalBanksNo);
            cout << "Account Succesfully Created/n";

            break;
        case 2:

            boolVar = false;
            break;
        default:
            cout << "Eneterd Incorrect Input";
            break;
        }
    }
}
//main method
int main()
{
    Bank banks[100];
    int totalBanksNo = 0;
    bool Var = true;
    int userInput;
    while (Var)
    {
        cout << "1)Admin" << endl;
        cout << "2) User" << endl;
        cout << "3) Exit" << endl;
        cin >> userInput;
        switch (userInput)
        {
        case 1:
            Admin(banks, &totalBanksNo);
            break;
        case 2:
            User(banks, &totalBanksNo);
            break;
        case 3:
            Var = false;
            break;

        default:
            cout << "Eneterd Incorrect Input";
            break;
        }
    }

    return 0;
}

// ToDO
// admin can register Bank
// admin can remove Bank
// users can register to bank
// users can add money
// users can remove money
//

// Admin(banks, &totalBanksNo);
// User(banks, &totalBanksNo);
// User(banks, &totalBanksNo);
// Admin(banks, &totalBanksNo);