#include <fstream>
#include <iostream>
#include "user.h"
#include "bill.h"
#include "transaction.h"
#include "menu.h"

using namespace std;

int main(int argc, char **argv)
{
    while (1)
    {
        int userId = print_home_menu();
        if(userId == 0)
            continue;
        if (userId == -1)
            return 0;

        string userName = User::user_userName(userId), password = User::user_password(userId);

        User logged_user(userName, password, userId);

        print_menu(logged_user);
    }

    return 0;
}