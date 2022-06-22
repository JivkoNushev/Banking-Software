#include "bill.h"
#include "user.h"
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
    void set_password(string new_password) { password = new_password; }
    void set_id(int new_id) { userId = new_id; }

    string get_name() { return userName; }
    string get_password() { return password; }
    int get_id() { return userId; }

    void add_user()
    {
        ofstream file;
        file.open("user_database.txt", ios::app);
        if (!file) return;
        file.write((char*)this, sizeof(*this));
        file.close();
    }

    static bool username_exists(string username)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);

        User current_user;

        file.read((char*)&current_user, sizeof(current_user));
        do
        {
            if (current_user.get_name() == username)
            {
                file.close();
                return true;
            }
            file.read((char*)&current_user, sizeof(current_user));
        } while (!file.eof());
        file.close();
        return false;
    }

    static bool user_exists(string username, string password)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);

        User current_user;

        file.read((char*)&current_user, sizeof(current_user));
        do
        {
            if (current_user.get_name() == username && current_user.get_password() == hash_string(password))
            {
                file.close();
                return true;
            }
            file.read((char*)&current_user, sizeof(current_user));
        } while (!file.eof());
        file.close();
        return false;
    }

    static int user_id(string username)
    {
        ifstream file;
        file.open("user_database.txt", ios::in);

        User current_user;

        file.read((char*)&current_user, sizeof(current_user));
        do
        {
            if (current_user.get_name() == username)
            {
                file.close();
                return current_user.get_id();
            }
            file.read((char*)&current_user, sizeof(current_user));
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
        float amount = 0, curr_balance = Bill::find_balance(userId);
        cout << "Enter withdraw amount: ";
        cin >> amount;

        if(amount < 0 || curr_balance < amount)
        {
            cout << "\nCan't withdraw that amount\n";
            return false;
        }

        Bill::change_balance(userId, curr_balance - amount);
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

    bool transfer()
    {
        float amount = 0;
        string billNumber;

        cout << "Enter transfer amount: ";
        cin >> amount;
        cout << "Enter bill number: ";
        cin >> billNumber;

        if(amount < 0 || Bill::bill_exists(billNumber))
        {
            cout << "\nCan't transfer that amount to that billNumber\n";
            return false;
        }   
        //Ако въведените данни са правилни се генерира запис за транзакция и се добавя в опашката за транзакции

        return true;
    } 
};