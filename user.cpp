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
    ofstream user_file;
    user_file.open("user_database.txt", ios::app);
    if (!user_file)
    {
        cout << "File error" << endl;
        return;
    }

    ofstream bill_file;
    bill_file.open("bill_database.txt", ios::app);
    if (!bill_file)
    {
        cout << "File error" << endl;
        return;
    }
    user_file << *this;
    Bill new_bill(Bill::create_bill_number(userId), userId, 0);
    bill_file << new_bill;

    user_file.close();
    bill_file.close();
    cout << "User added!" << endl;
}

bool User::username_exists(string username)
{
    ifstream file;
    file.open("user_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    if (file.peek() == std::ifstream::traits_type::eof())
        return false;

    file >> currentUser;
    do
    {
        if (currentUser.get_name() == username)
        {
            file.close();
            return true;
        }
        file >> currentUser;
    } while (file.good());

    file.close();
    return false;
}

bool User::user_exists(string username, string password)
{
    ifstream file;
    file.open("user_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return false;
    }

    User currentUser;

    file >> currentUser;
    do
    {
        if (currentUser.get_name() == username && currentUser.get_password() == hash_string(password))
        {
            file.close();
            return true;
        }
        file >> currentUser;
    } while (file.good());
    file.close();
    return false;
}

string User::user_userName(int userId)
{
    ifstream file;
    file.open("user_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    file >> currentUser;
    do
    {
        if (currentUser.get_id() == userId)
        {
            file.close();
            return currentUser.get_name();
        }
        file >> currentUser;
    } while (file.good());

    file.close();
    return 0;
}

string User::user_password(int userId)
{
    ifstream file;
    file.open("user_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;

    file >> currentUser;
    do
    {
        if (currentUser.get_id() == userId)
        {
            file.close();
            return currentUser.get_password();
        }
        file >> currentUser;
    } while (file.good());

    file.close();
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
    ifstream file;
    file.open("user_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    User currentUser;
    file >> currentUser;
    do
    {
        if (currentUser.get_name() == username)
        {
            file.close();
            return currentUser.get_id();
        }
        file >> currentUser;
    } while (file.good());

    file.close();
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

    ofstream file;
    file.open("transactions.txt", ios::app);
    if (!file)
    {
        cout << "File error" << endl;
        return false;
    }
    file << newTransaction;
    file.close();

    return true;
}
