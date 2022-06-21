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
    Bill(string billNumber, string userId, float balance);

    void set_billNumber(string bill_Number);
    void set_userId(string user_Id);
    void set_balance(float new_balance);

    string get_billNumber();
    int get_userId();
    float get_balance();

    static float find_balance(int userId);
    static void change_balance(int userId, float newBalance);        
    static bool bill_exists(string billNumber);
};