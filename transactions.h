#include <string>
using namespace std;

class Transaction
{
    string operationCode, billNumberFrom, billNumberTo;
    float transferAmount;
public:
    Transaction(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount);

    void set_operationCode(string newOperationCode);
    void set_billNumberFrom(string newBillNumberFrom);
    void set_billNumberTo(string newBillNumberTo);
    void set_transferAmount(float newTransferAmount);

    string get_operationCode();
    string get_billNumberFrom();
    string get_billNumberTo();
    float get_transferAmount();
};