#include <fstream>
#include <iostream>
#include "bill.h"
#include "user.h"
#include "transaction.h"
#include "hash.h"

User::User() {}
User::User(string userName, string password, int userId) : userName(userName), password(password), userId(userId) {}

void User::set_name(string name) { userName = name; }
void User::set_password(string newPassword) { password = newPassword; }
void User::set_id(int newId) { userId = newId; }

string User::get_name() { return userName; }
string User::get_password() { return password; }
int User::get_id() { return userId; }

ostream &operator<<(ostream &os, User &user)
{
    os << user.userName << endl
       << user.password << endl
       << user.userId;
    return os;
}
istream &operator>>(istream &is, User &user)
{
    is >> user.userName >> user.password >> user.userId;
    return is;
}

void User::add_user()
{
    ofstream userFile;
    userFile.open("user_database.txt", ios::app);
    if (!userFile)
    {
        cout << "File error" << endl;
        return;
    }

    ofstream billFile;
    billFile.open("bill_database.txt", ios::app);
    if (!billFile)
    {
        cout << "File error" << endl;
        return;
    }
    userFile << *this << "\n";
    Bill newBill(Bill::create_bill_number(userId), userId, 0);
    billFile << newBill << "\n";

    userFile.close();
    billFile.close();
    cout << "User added!" << endl;
}

bool User::username_exists(string username)
{
    ifstream userFile;
    userFile.open("user_database.txt", ios::in);
    if (!userFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    if (userFile.peek() == std::ifstream::traits_type::eof())
        return false;

    userFile >> currentUser;
    do
    {
        if (currentUser.get_name() == username)
        {
            userFile.close();
            return true;
        }
        userFile >> currentUser;
    } while (userFile.good());

    userFile.close();
    return false;
}

bool User::user_exists(string username, string password)
{
    ifstream userFile;
    userFile.open("user_database.txt", ios::in);
    if (!userFile)
    {
        cout << "File error" << endl;
        return false;
    }

    User currentUser;

    userFile >> currentUser;
    do
    {
        if (currentUser.get_name() == username && currentUser.get_password() == password)
        {
            userFile.close();
            return true;
        }
        userFile >> currentUser;
    } while (userFile.good());
    userFile.close();
    return false;
}

string User::user_userName(int userId)
{
    ifstream userFile;
    userFile.open("user_database.txt", ios::in);
    if (!userFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    userFile >> currentUser;
    do
    {
        if (currentUser.get_id() == userId)
        {
            userFile.close();
            return currentUser.get_name();
        }
        userFile >> currentUser;
    } while (userFile.good());

    userFile.close();
    return 0;
}

string User::user_password(int userId)
{
    ifstream userFile;
    userFile.open("user_database.txt", ios::in);
    if (!userFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    userFile >> currentUser;
    do
    {
        if (currentUser.get_id() == userId)
        {
            userFile.close();
            return currentUser.get_password();
        }
        userFile >> currentUser;
    } while (userFile.good());

    userFile.close();
    return 0;
}

int User::generate_id(string username)
{
    const int p = 31, m = 1e9 + 7;
    int hashValue = 0;
    long pPow = 1;
    const int n = username.length();
    for (int i = 0; i < n; ++i)
    {
        hashValue = (hashValue + (username[i] - 'a' + 1) * pPow) % m;
        pPow = (pPow * p) % m;
    }
    return hashValue;
}

int User::user_id(string username)
{
    ifstream userFile;
    userFile.open("user_database.txt", ios::in);
    if (!userFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;
    userFile >> currentUser;
    do
    {
        if (currentUser.get_name() == username)
        {
            userFile.close();
            return currentUser.get_id();
        }
        userFile >> currentUser;
    } while (userFile.good());

    userFile.close();
    return 0;
}

bool User::withdraw()
{
    float amount = 0, currBalance = Bill::find_balance(userId);
    cout << "Enter withdraw amount: ";
    cin >> amount;

    if (amount < 0 || currBalance < amount)
    {
        cout << "\nCan't withdraw that amount\n";
        return false;
    }

    Bill::change_balance(userId, currBalance - amount);
    return true;
}

bool User::deposit()
{
    float amount = 0;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (amount < 0)
    {
        cout << "\nCan't deposit that amount\n";
        return false;
    }

    Bill::change_balance(userId, Bill::find_balance(userId) + amount);
    return true;
}

bool User::transfer()
{
    float transferAmount = 0;
    string billNumberTo = "";

    cout << "Enter transfer amount: ";
    cin >> transferAmount;
    cout << "Enter bill number: ";
    cin >> billNumberTo;

    if (transferAmount < 0 || Bill::bill_exists(billNumberTo))
    {
        cout << "\nCan't transfer that amount to that billNumber\n";
        return false;
    }

    string billNumberFrom = Bill::find_bill_number(this->get_id());
    string operationCode = "transfer";
    Transaction newTransaction(operationCode, billNumberFrom, billNumberTo, transferAmount);

    ofstream transactionFile;
    transactionFile.open("transactions.txt", ios::app);
    if (!transactionFile)
    {
        cout << "File error" << endl;
        return false;
    }
    transactionFile << newTransaction;
    transactionFile.close();

    return true;
}
