#include "bill.h"
#include "user.h"
#include "transaction.h"
#include "hash.h"

class User
{
    string userName, password;
    int userId;
public:
    User()
    {}
    User(string userName, string password, int userId): userName(userName), password(password), userId(userId) 
    {}
    
    void set_name(string name) { userName = name; }
    void set_password(string newPassword) { password = newPassword; }
    void set_id(int newId) { userId = newId; }

    string get_name() { return userName; }
    string get_password() { return password; }
    int get_id() { return userId; }

    void add_user()
    {
        ofstream file;
        file.open("user_database.txt", ios::app);
        if(!file)
        {
            cout << "File error" << endl;
            return;
        }

        file.write((char*)this, sizeof(*this));
        file.close();
    }

    static bool username_exists(string username)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);
        if(!file)
        {
            cout << "File error" << endl;
            return false;
        }

        User currentUser;

        file.read((char*)&currentUser, sizeof(currentUser));
        do
        {
            if (currentUser.get_name() == username)
            {
                file.close();
                return true;
            }
            file.read((char*)&currentUser, sizeof(currentUser));
        } while (!file.eof());
        file.close();
        return false;
    }

    static bool user_exists(string username, string password)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);
        if(!file)
        {
            cout << "File error" << endl;
            return false;
        }

        User currentUser;

        file.read((char*)&currentUser, sizeof(currentUser));
        do
        {
            if (currentUser.get_name() == username && currentUser.get_password() == hash_string(password))
            {
                file.close();
                return true;
            }
            file.read((char*)&currentUser, sizeof(currentUser));
        } while (!file.eof());
        file.close();
        return false;
    }

    static int user_id(string username)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);
        if(!file)
        {
            cout << "File error" << endl;
            return 0;
        }

        User currentUser;

        file.read((char*)&currentUser, sizeof(currentUser));
        do
        {
            if (currentUser.get_name() == username)
            {
                file.close();
                return currentUser.get_id();
            }
            file.read((char*)&currentUser, sizeof(currentUser));
        } while (!file.eof());        
        file.close();
        return 0;
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
        float amount = 0, currBalance = Bill::find_balance(userId);
        cout << "Enter withdraw amount: ";
        cin >> amount;

        if(amount < 0 || currBalance < amount)
        {
            cout << "\nCan't withdraw that amount\n";
            return false;
        }

        Bill::change_balance(userId, currBalance - amount);
        return true;
    }

    bool deposit()
    {
        float amount = 0;
        cout << "Enter deposit amount: ";
        cin >> amount;

        if(amount < 0)
        {
            cout << "\nCan't deposit that amount\n";
            return false;
        }

        Bill::change_balance(userId, Bill::find_balance(userId) + amount);
        return true;
    }

    bool transfer(queue<Transaction> *queue)
    {
        float transferAmount = 0;
        string billNumberTo;

        cout << "Enter transfer amount: ";
        cin >> transferAmount;
        cout << "Enter bill number: ";
        cin >> billNumberTo;
        
        if(transferAmount < 0 || Bill::bill_exists(billNumberTo))
        {
            cout << "\nCan't transfer that amount to that billNumber\n";
            return false;
        }
        
        string billNumberFrom = Bill::find_bill_number(this->get_id());
        string operationCode = "transfer";
        Transaction newTransaction(operationCode,billNumberFrom,billNumberTo,transferAmount);

        ofstream file;
        file.open("transactions.txt", ios::app);
        if(!file)
        {
            cout << "File error" << endl;
            return false;
        }

        file.write((char*)&newTransaction, sizeof(newTransaction));
        file.close();

        (*queue).push(newTransaction);
        return true;
    } 
};