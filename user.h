#include <fstream>
#include <iostream>
#include <string>
#include "bill.h"
using namespace std;

class User
{
    string userName, password;
    int userId;
public:
    User(string userName, string password, int userId);

    void set_name(string name);
    void set_password(string newPassword);
    void set_id(int newId);

    string get_name();
    string get_password();
    int get_id();

    string add_user();

    static bool user_exists(string username, string password);

    static int user_id(string username);

    static bool username_exists(string username);

    static int generate_id(string username);

    bool withdraw();

    bool deposit();

    bool transfer();
};