#ifndef USER
#define USER

#include <string>
#include <fstream>
using namespace std;

class User
{
    string userName, password;
    int userId;

public:
    User();
    User(string userName, string password, int userId);

    void set_name(string name);
    void set_password(string newPassword);
    void set_id(int newId);

    string get_name();
    string get_password();
    int get_id();

    friend ostream &operator<<(ostream &os, User &user);
    friend istream &operator>>(istream &is, User &user);

    void add_user();

    static bool username_exists(string username);

    static bool user_exists(string username, string password);

    static string user_userName(int userId);

    static string user_password(int userId);

    static int generate_id(string username);

    static int user_id(string username);

    bool withdraw();

    bool deposit();

    bool transfer();
};

#endif