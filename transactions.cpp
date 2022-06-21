#include "transactions.h"

class Transactions
{
    string operationCode, billNumberFrom, billNumberTo;
    float transferAmount;
public:
    Transactions(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount): 
    operationCode(operationCode), billNumberFrom(billNumberFrom), billNumberTo(billNumberTo), transferAmount(transferAmount)
    {}

    void set_operationCode(string new_operationCode) { operationCode = new_operationCode; }
    void set_billNumberFrom(string new_billNumberFrom) { billNumberFrom = new_billNumberFrom; }
    void set_billNumberTo(string new_billNumberTo) { billNumberTo = new_billNumberTo; }
    void set_transferAmount(float new_transferAmount) { transferAmount = new_transferAmount; }

    string get_operationCode() { return operationCode; }
    string get_billNumberFrom() { return billNumberFrom; }
    string get_billNumberTo() { return billNumberTo; }
    float get_transferAmount() { return transferAmount; }

};