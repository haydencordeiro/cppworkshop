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
        int age = 1;
        string name;
        cout << "Enter Your Age \t";
        // cin >> age;
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
    cin >> userInput;

    switch (userInput)
    {
        // 1 register
        //2 remove
        //3 show all customers of a bank
    case 1:
        banks[*totalBanksNo] = Bank("SBI");
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
    }
}

void User(Bank *banks, int *totalBanksNo)
{

    int userInput = 1;
    string bname;
    //1 Register
    switch (userInput)
    {
    case 1:

        DisplayAllBanks(banks, totalBanksNo);
        cout << "Enter the name of a bank you want to create an account in" << endl;
        cin >> bname;
        InsertUser(bname, banks, totalBanksNo);

        break;
    }
}
//main method
int main()
{
    Bank banks[100];
    int totalBanksNo = 0;

    Admin(banks, &totalBanksNo);
    User(banks, &totalBanksNo);
    User(banks, &totalBanksNo);
    Admin(banks, &totalBanksNo);

    return 0;
}

// ToDO
// admin can register Bank
// admin can remove Bank
// users can register to bank
// users can add money
// users can remove money
