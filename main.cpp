#include <fstream>
#include <iostream>
#include "user.h"
#include "bill.h"
#include "transaction.h"
#include "menu.h"

using namespace std;

/////// main isnt in github

int main(int argc, char **argv)
{
    // string a = "name", b = "pass";
    // User inputu(a, b, 123);
    // ofstream user_file;
    // user_file.open("user_database.txt", ios::app);
    // user_file << inputu << endl;
    // user_file.close();

    // cout << "added" << endl;

    // ifstream file;
    // file.open("user_database.txt", ios::in);

    // User currentUser, tmpUser;
    // file >> currentUser;
    // do
    // {
    //     cout << currentUser << endl;
    //     file >> currentUser;
    // } while (file.good());

    while (1)
    {
        int userId = print_home_menu();
        if (userId == -1)
            return 0;

        string userName = User::user_userName(userId), password = User::user_password(userId);

        User logged_user(userName, password, userId);

        print_menu(logged_user);
    }

    return 0;
}