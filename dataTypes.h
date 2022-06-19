#ifndef DATATYPES
#define DATATYPES

#include <string>

using namespace std;

class User
{
    string userName, password, userId;
public:
    User(string userName, string password, string userId): userName(userName), password(password), userId(userId) 
    {}
    
    void set_name(string name) { userName = name; }
    void set_password(string new_password) { password = new_password; }
    void set_id(string new_id) { userId = new_id; }

    string get_name() { return userName; }
    string get_password() { return password; }
    string get_id() { return userId; }

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
