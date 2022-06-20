#ifndef DATATYPES
#define DATATYPES

#include <string>

using namespace std;

class User
{
    string userName, password;
    int userId;
public:
User(){}
    User(string userName, string password, int userId): userName(userName), password(password), userId(userId) 
    {}
    
    void set_name(string name) { userName = name; }
    void set_password(string new_password) { password = new_password; }
    void set_id(int new_id) { userId = new_id; }

    string get_name() { return userName; }
    string get_password() { return password; }
    int get_id() { return userId; }

<<<<<<< HEAD
    void set_balance(float new_balance)
    {

    }

    float get_balance()
    {

    }

    bool withdraw()
    {
        float amount = 0, curr_balance = get_balance();
        cin >> amount;

        if(amount < 0 || curr_balance < amount)
        {
            cout << "\nCan't withdraw that amount\n";
            return false;
        }

        set_balance(curr_balance - amount);
        return true;
    }

    bool deposit()
    {
        float amount = 0;
        cin >> amount;

        if(amount < 0)
        {
            cout << "\nCan't deposit that amount\n";
            return false;
        }

        set_balance(get_balance() + amount);
        return true;
    }

    bool transfer()
    {
        float amount = 0;
        cin >> amount;
        string billNumber;
        cin >> billNumber;

        if(amount < 0 || Bill::bill_exists(billNumber))
        {
            cout << "\nCan't transfer that amount to that billNumber\n";
            return false;
        }   

        return true;
    }

=======
    int user_id(string username)
    {
        const int p = 31, m = 1e9 + 7;
        int hash_value = 0;
        long p_pow = 1;
        const int n = username.length();
        for (int i = 0; i < n; ++i) {
            hash_value = (hash_value + (username[i] - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
    void withdraw();
    void deposit();
    void transfer();
>>>>>>> 1d71e9a7f7102c42f9b2263e67abfa25fa2c1963
    void transactions();

};

class Bill
{
    string billNumber, userId;
    float balance;
public:
    Bill(string billNumber, string userId, float balance): billNumber(billNumber), userId(userId), balance(balance)
    {}

    void set_billNumber(string bill_Number) { billNumber = bill_Number; }
    void set_userId(string user_Id) { userId = user_Id; }
    void set_balance(float new_balance) { balance = new_balance; }

    string get_billNumber() { return billNumber; }
    string get_userId() { return userId; }
    float get_balance() { return balance; }

    static bool bill_exists(string billNumber)
    {
        
    }

};

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

#endif
