#include <fstream>
#include <iostream>
#include "bill.h"

using namespace std;

Bill::Bill() {}
Bill::Bill(string billNumber, int userId, float balance) : billNumber(billNumber), userId(userId), balance(balance) {}

void Bill::set_billNumber(string newBillNumber) { billNumber = newBillNumber; }
void Bill::set_userId(int newUserId) { userId = newUserId; }
void Bill::set_balance(float newBalance) { balance = newBalance; }

string Bill::get_billNumber() { return billNumber; }
int Bill::get_userId() { return userId; }
float Bill::get_balance() { return balance; }
ostream &operator<<(ostream &os, Bill &bill)
{
    os << bill.billNumber << endl
       << bill.userId << endl
       << bill.balance;
    return os;
}
istream &operator>>(istream &is, Bill &bill)
{
    is >> bill.billNumber >> bill.userId >> bill.balance;
    return is;
}

float Bill::find_balance(int userId)
{
    ifstream file;
    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_userId() == userId)
        {
            file.close();
            return current_bill.get_balance();
        }
        file >> current_bill;
    } while (file.good());

    file.close();
    return 0;
}

float Bill::find_balance(string billNumber)
{
    ifstream file;
    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_billNumber() == billNumber)
        {
            file.close();
            return current_bill.get_balance();
        }
        file >> current_bill;
    } while (file.good());

    file.close();
    return 0;
}

bool Bill::change_balance(int userId, float newBalance)
{
    ifstream file;
    ofstream buffer;

    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    buffer.open("buffer_file.txt", ios::app);
    if (!buffer)
    {
        file.close();
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_userId() == userId)
            current_bill.set_balance(newBalance);
        buffer << current_bill;
        file >> current_bill;
    } while (file.good());

    file.close();
    buffer.close();

    remove("bill_database.txt");
    rename("buffer_file.txt", "bill_database.txt");

    return 1;
}

bool Bill::change_balance(string billNumber, float newBalance)
{
    ifstream file;
    ofstream buffer;

    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    buffer.open("buffer_file.txt", ios::app);
    if (!buffer)
    {
        file.close();
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_billNumber() == billNumber)
            current_bill.set_balance(newBalance);
        buffer << current_bill;
        file >> current_bill;
    } while (file.good());

    file.close();
    buffer.close();

    remove("bill_database.txt");
    rename("buffer_file.txt", "bill_database.txt");

    return 1;
}

bool Bill::bill_exists(string billNumber)
{
    ifstream file;
    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_billNumber() == billNumber)
        {
            file.close();
            return true;
        }
        file >> current_bill;
    } while (file.good());

    file.close();
    return false;
}

string Bill::find_bill_number(int userId)
{
    ifstream file;
    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_userId() == userId)
        {
            file.close();
            return current_bill.get_billNumber();
        }
        file >> current_bill;
    } while (file.good());

    file.close();
}

int Bill::find_user_id(string billNumber)
{
    ifstream file;
    file.open("bill_database.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill current_bill;
    file >> current_bill;
    do
    {
        if (current_bill.get_billNumber() == billNumber)
        {
            file.close();
            return current_bill.get_userId();
        }
        file >> current_bill;
    } while (file.good());
    
    file.close();
}

string Bill::create_bill_number(int userId)
{
    return to_string(userId + rand() % 1000);
}
