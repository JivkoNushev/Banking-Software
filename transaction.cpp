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

    static void process_transactions(queue<Transaction> *queue)
    {
        
        while (!(*queue).empty())
        {
            Transaction currentTransaction = (*queue).front();
            //get current balance
            //check if enough money
            //remove money from "From"
            //give money to "To"
            (*queue).pop();
        }
    }
};