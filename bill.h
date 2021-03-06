#ifndef BILL
#define BILL
#include <fstream>
#include <string>
#include "user.h"
using namespace std;

class Bill
{
    string billNumber;
    int userId;
    float balance;

public:
    Bill();
    Bill(string billNumber, int userId, float balance);

    void set_billNumber(string newBillNumber);
    void set_userId(int newUserId);
    void set_balance(float newBalance);

    string get_billNumber();
    int get_userId();
    float get_balance();

    friend ostream &operator<<(ostream &os, Bill &bill);
    friend istream &operator>>(istream &is, Bill &bill);

    static float find_balance(int userId);

    static float find_balance(string billNumber);

    static bool change_balance(int userId, float newBalance);

    static bool change_balance(string billNumber, float newBalance);

    static bool bill_exists(string billNumber);

    static string find_bill_number(int userId);

    static int find_user_id(string billNumber);

    static string create_bill_number(int userId);
};

#endif