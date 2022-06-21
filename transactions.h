#include <string>
using namespace std;

class Transactions
{
    string operationCode, billNumberFrom, billNumberTo;
    float transferAmount;
public:
    Transactions(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount);

    void set_operationCode(string new_operationCode);
    void set_billNumberFrom(string new_billNumberFrom);
    void set_billNumberTo(string new_billNumberTo);
    void set_transferAmount(float new_transferAmount);

    string get_operationCode();
    string get_billNumberFrom();
    string get_billNumberTo();
    float get_transferAmount();
};