#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Bill
{
    string billNumber;
    int userId;
    float balance;
public:
    Bill(string billNumber, int userId, float balance);

    void set_billNumber(string billNumber);
    void set_userId(int userId);
    void set_balance(float newBalance);

    string get_billNumber();
    int get_userId();
    float get_balance();

    static float find_balance(int userId);
    static void change_balance(int userId, float newBalance);        
    static bool bill_exists(string billNumber);
    string find_bill_number(int userId);
};