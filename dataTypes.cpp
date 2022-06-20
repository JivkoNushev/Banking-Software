#include <fstream>
#include <iostream>
#include <string>
#include "dataTypes.h"
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

    string add_user()
    {
        ofstream file;
        file.open("user_database.txt", ios::app);
        if (!file)
            return "";
        file.write((char*)this, sizeof(*this));
        file.close();
    }

    static bool username_exists(string username)
    {
        ifstream file;
        file.open("Database.txt", ios::in);

        User current_user;

        file.read((char*)&current_user, sizeof(current_user));
        do
        {
            if (current_user.get_name() == username)
                return true;
            file.read((char*)&current_user, sizeof(current_user));
        } while (!file.eof());
        return false;
    }

    static int generate_id(string username)
    {
        const int p = 31, m = 1e9 + 7;
        int hashValue = 0;
        long pPow = 1;
        const int n = username.length();
        for (int i = 0; i < n; ++i) {
            hashValue = (hashValue + (username[i] - 'a' + 1) * pPow) % m;
            pPow = (pPow * p) % m;
        }
        return hashValue;
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
