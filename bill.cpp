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
    ifstream billFile;
    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_userId() == userId)
        {
            billFile.close();
            return currentBill.get_balance();
        }
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    return 0;
}

float Bill::find_balance(string billNumber)
{
    ifstream billFile;
    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_billNumber() == billNumber)
        {
            billFile.close();
            return currentBill.get_balance();
        }
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    return 0;
}

bool Bill::change_balance(int userId, float newBalance)
{
    ifstream billFile;
    ofstream bufferFile;

    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    bufferFile.open("buffer_file.txt", ios::app);
    if (!bufferFile)
    {
        billFile.close();
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_userId() == userId)
            currentBill.set_balance(newBalance);
        bufferFile << currentBill;
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    bufferFile.close();

    remove("bill_database.txt");
    rename("buffer_file.txt", "bill_database.txt");

    return 1;
}

bool Bill::change_balance(string billNumber, float newBalance)
{
    ifstream billFile;
    ofstream bufferFile;

    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    bufferFile.open("buffer_file.txt", ios::app);
    if (!bufferFile)
    {
        billFile.close();
        cout << "File error" << endl;
        return 0;
    }
    
    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_billNumber() == billNumber)
            currentBill.set_balance(newBalance);
        bufferFile << currentBill;
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    bufferFile.close();

    remove("bill_database.txt");
    rename("buffer_file.txt", "bill_database.txt");

    return 1;
}

bool Bill::bill_exists(string billNumber)
{
    ifstream billFile;
    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_billNumber() == billNumber)
        {
            billFile.close();
            return true;
        }
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    return false;
}

string Bill::find_bill_number(int userId)
{
    ifstream billFile;
    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_userId() == userId)
        {
            billFile.close();
            return currentBill.get_billNumber();
        }
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    return 0;
}

int Bill::find_user_id(string billNumber)
{
    ifstream billFile;
    billFile.open("bill_database.txt", ios::in);
    if (!billFile)
    {
        cout << "File error" << endl;
        return 0;
    }

    Bill currentBill;
    billFile >> currentBill;
    do
    {
        if (currentBill.get_billNumber() == billNumber)
        {
            billFile.close();
            return currentBill.get_userId();
        }
        billFile >> currentBill;
    } while (billFile.good());

    billFile.close();
    return 0;
}

string Bill::create_bill_number(int userId)
{
    return to_string(userId + rand() % 1000);
}
