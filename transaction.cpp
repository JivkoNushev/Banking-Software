#include <fstream>
#include <iostream>
#include "transaction.h"
#include "bill.h"

Transaction::Transaction() {}
Transaction::Transaction(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount) : operationCode(operationCode), billNumberFrom(billNumberFrom), billNumberTo(billNumberTo), transferAmount(transferAmount) {}

void Transaction::set_operationCode(string newOperationCode) { operationCode = newOperationCode; }
void Transaction::set_billNumberFrom(string newBillNumberFrom) { billNumberFrom = newBillNumberFrom; }
void Transaction::set_billNumberTo(string newBillNumberTo) { billNumberTo = newBillNumberTo; }
void Transaction::set_transferAmount(float newTransferAmount) { transferAmount = newTransferAmount; }

string Transaction::get_operationCode() { return operationCode; }
string Transaction::get_billNumberFrom() { return billNumberFrom; }
string Transaction::get_billNumberTo() { return billNumberTo; }
float Transaction::get_transferAmount() { return transferAmount; }

ostream &operator<<(ostream &os, Transaction &transaction)
{
    os << transaction.operationCode << endl
       << transaction.billNumberFrom << endl
       << transaction.billNumberTo << endl
       << transaction.transferAmount;
    return os;
}
istream &operator>>(istream &is, Transaction &transaction)
{
    is >> transaction.operationCode >> transaction.billNumberFrom >> transaction.billNumberTo >> transaction.transferAmount;
    return is;
}

bool Transaction::process_transactions()
{
    ifstream file;
    file.open("transactions.txt", ios::in);
    if (!file)
    {
        cout << "File error" << endl;
        return false;
    }

    Transaction currentTransaction;
    file >> currentTransaction;
    do
    {
        if (!Bill::bill_exists(currentTransaction.billNumberFrom) || !Bill::bill_exists(currentTransaction.billNumberFrom))
        {
            cout << "Invalid bill number!" << endl;
            return false;
        }
        float balanceFrom = Bill::find_balance(currentTransaction.billNumberFrom);
        float balanceTo = Bill::find_balance(currentTransaction.billNumberTo);
        // check if enough money From
        if (balanceFrom < 0)
        {
            cout << "Invalid balance!" << endl;
            continue;
        }

        // remove money from "From"
        Bill::change_balance(currentTransaction.billNumberFrom, balanceFrom - currentTransaction.transferAmount);
        // give money to "To"
        Bill::change_balance(currentTransaction.billNumberTo, balanceTo + currentTransaction.transferAmount);

        // read next
        file >> currentTransaction;
    } while (file.good());

    file.close();

    // delete processed transactions
    ofstream f("transactions.txt");
    f.close();

    return true;
}