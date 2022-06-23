#include "transaction.h"
#include "bill.h"

class Transaction
{
    string operationCode, billNumberFrom, billNumberTo;
    float transferAmount;
public:
    Transaction(){}
    Transaction(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount): 
    operationCode(operationCode), billNumberFrom(billNumberFrom), billNumberTo(billNumberTo), transferAmount(transferAmount)
    {}

    void set_operationCode(string newOperationCode) { operationCode = newOperationCode; }
    void set_billNumberFrom(string newBillNumberFrom) { billNumberFrom = newBillNumberFrom; }
    void set_billNumberTo(string newBillNumberTo) { billNumberTo = newBillNumberTo; }
    void set_transferAmount(float newTransferAmount) { transferAmount = newTransferAmount; }

    string get_operationCode() { return operationCode; }
    string get_billNumberFrom() { return billNumberFrom; }
    string get_billNumberTo() { return billNumberTo; }
    float get_transferAmount() { return transferAmount; }

    static bool process_transactions()
    {
        ifstream file;
        file.open("transactions.txt",ios::in);
        if(!file)
        {
            cout << "File error" << endl;
            return false;
        }

        Transaction currentTransaction;

        file.read((char*)&currentTransaction, sizeof(currentTransaction));
        do
        {
            if(!Bill::bill_exists(currentTransaction.billNumberFrom) || !Bill::bill_exists(currentTransaction.billNumberFrom))
            {
                cout << "Invalid bill number!" << endl;
                return false;
            }
            int userIdFrom = Bill::find_user_id(currentTransaction.billNumberFrom);
            int userIdTo = Bill::find_user_id(currentTransaction.billNumberTo);

            //get current balance
            float balanceFrom = Bill::find_balance(userIdFrom);
            float balanceTo = Bill::find_balance(userIdTo);
            //check if enough money From
            if(balanceFrom < 0)
            {
                cout << "Invalid balance!"<< endl;
                continue;
            }
            //remove money from "From"
            Bill::change_balance(userIdFrom,balanceFrom - currentTransaction.transferAmount);
            //give money to "To"
            Bill::change_balance(userIdTo,balanceTo + currentTransaction.transferAmount);
            //pop

            file.read((char*)&currentTransaction, sizeof(currentTransaction));
        } while (!file.eof());

            

        file.close();
        return true;
    }
};