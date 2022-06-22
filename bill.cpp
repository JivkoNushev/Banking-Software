#include "bill.h"

class Bill
{
    string billNumber;
    int userId;
    float balance;
public:
    Bill()
    {}
    Bill(string billNumber, int userId, float balance): billNumber(billNumber), userId(userId), balance(balance)
    {}

    void set_billNumber(string newBillNumber) { billNumber = newBillNumber; }
    void set_userId(int newUserId) { userId = newUserId; }
    void set_balance(float newBalance) { balance = newBalance; }

    string get_billNumber() { return billNumber; }
    int get_userId() { return userId; }
    float get_balance() { return balance; }

    static float find_balance(int userId)
    {
        ifstream file;
        file.open("bill_database.txt", ios::in);

        Bill current_bill;

        file.read((char*)&current_bill, sizeof(current_bill));
        do
        {
            if (current_bill.get_userId() == userId)
            {
                file.close();
                return current_bill.get_balance();
            }
            file.read((char*)&current_bill, sizeof(current_bill));
        } while (!file.eof());
        return 0;
    }

    static float change_balance(int userId, float newBalance)
    {
        ifstream file;
        ofstream buffer;
        file.open("bill_database.txt", ios::in);
        buffer.open("buffer_file.txt", ios::app);

        Bill current_bill;

        file.read((char*)&current_bill, sizeof(current_bill));
        do
        {
            if (current_bill.get_userId() == userId)
                current_bill.set_balance(newBalance);
            buffer.write((char*)&current_bill, sizeof(current_bill));
            file.read((char*)&current_bill, sizeof(current_bill));
        } while (!file.eof());
        file.close();
        buffer.close();
        remove("bill_database.txt");
        rename("buffer_file.txt", "bill_database.txt");
        return 0;
    }

    static bool bill_exists(string billNumber)
    {
        ifstream file;
        file.open("bill_database.txt", ios::in);

        Bill current_bill;

        file.read((char*)&current_bill, sizeof(current_bill));
        do
        {
            if (current_bill.get_billNumber() == billNumber)
            {
                file.close();
                return true;
            }
            file.read((char*)&current_bill, sizeof(current_bill));
        } while (!file.eof());
        file.close();
        return false;
    }

    string find_bill_number(int userId)
    {
        ifstream file;
        file.open("bill_database.txt", ios::in);

        Bill current_bill;

        file.read((char*)&current_bill, sizeof(current_bill));
        do
        {
            if (current_bill.get_userId() == userId)
            {
                file.close();
                return current_bill.get_billNumber();
            }
            file.read((char*)&current_bill, sizeof(current_bill));
        } while (!file.eof());
        file.close();
        return false;
    }
};