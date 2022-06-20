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

    string add_user()
    {
        ofstream file;
        file.open("user_database.txt", ios::app);
        if (!file)
            return "";
        file.write((char*)this, sizeof(*this));
        file.close();
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

    void withdraw();
    void deposit();
    void transfer();
    void transactions();

};

class Bill
{
    string billNumber, userId;
    int balance;
public:
    Bill(string billNumber, string userId, int balance): billNumber(billNumber), userId(userId), balance(balance)
    {}

    void set_billNumber(string bill_Number) { billNumber = bill_Number; }
    void set_userId(string user_Id) { userId = user_Id; }
    void set_balance(int new_balance) { balance = new_balance; }

    string get_billNumber() { return billNumber; }
    string get_userId() { return userId; }
    int get_balance() { return balance; }

};

class Transactions
{
    string operationCode, billNumberFrom, billNumberTo;
    int transferAmount;
public:
    Transactions(string operationCode, string billNumberFrom, string billNumberTo, int transferAmount): 
    operationCode(operationCode), billNumberFrom(billNumberFrom), billNumberTo(billNumberTo), transferAmount(transferAmount)
    {}

    void set_operationCode(string new_operationCode) { operationCode = new_operationCode; }
    void set_billNumberFrom(string new_billNumberFrom) { billNumberFrom = new_billNumberFrom; }
    void set_billNumberTo(string new_billNumberTo) { billNumberTo = new_billNumberTo; }
    void set_transferAmount(int new_transferAmount) { transferAmount = new_transferAmount; }

    string get_operationCode() { return operationCode; }
    string get_billNumberFrom() { return billNumberFrom; }
    string get_billNumberTo() { return billNumberTo; }
    int get_transferAmount() { return transferAmount; }

};

#endif
