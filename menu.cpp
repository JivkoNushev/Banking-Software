#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include "menu.h"
#include "hash.h"
#include "user.h"
#include "transaction.h"
using namespace std;

void home_menu(int number)
{
    switch (number)
    {
    case 1:
        cout << "+----------------------------------------+\n"
                "|               Home menu                |\n"
                "| 1.Sign in                              |\n"
                "| 2.Sign up                              |\n"
                "| 3.Exit                                 |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "+----------------------------------------+\n";
        break;
    case 2:
        cout << "+----------------------------------------+\n"
                "|               Home menu                |\n"
                "| 1.Withdraw                             |\n"
                "| 2.Deposit                              |\n"
                "| 3.Transfer                             |\n"
                "| 4.Transactions                         |\n"
                "| 5.Logout                               |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "|                                        |\n"
                "+----------------------------------------+\n";
        break;
    }
}

int signin_menu()
{
    string username = "", password = "";

    system("clear");

    cout << "|               Sign in                   |\n";
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    if (!User::user_exists(username, password))
    {
        cout << "User doesn't exist!" << endl;
        return 0;
    }

    return User::user_id(username);
}

int signup_menu()
{
    string username = "", password = "";

    system("clear");

    cout << "|               Sign up                   |\n";
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    password = hash_string(password);
    if (User::username_exists(username))
    {
        cout << "Username exists!" << endl;
        return 0;
    }
    User user(username, password, User::generate_id(username));
    user.add_user();

    return user.get_id();
}

bool is_number(const string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int print_home_menu()
{
    string input;
    stringstream ss;
    int input_to_int;

    while (1)
    {
        /*
        do
        {
            system("clear");
            home_menu(1);
            getline(cin, input);
            ss << input;
            ss >> input;
            if(!is_number(input))
                continue;
            input_to_int = stoi(input);
        }while(input_to_int < 1 && input_to_int > 3);
        */
        system("clear");
        home_menu(1);
        cin >> input_to_int;
        getline(cin, input);

        switch (input_to_int)
        {
        case 1:
            return signin_menu();
        case 2:
            return signup_menu();
        case 3:
            system("clear");
            cout << "Exited from the bank" << endl;
            return -1;
        default:
            break;
        }
        system("clear");
    }
}

// :-
//////TODO: nikude ne se generira billNumber
//
void print_menu(User &user)
{
    string input;
    stringstream ss;
    int input_to_int;

    while (1)
    {
        /*do
        {
            system("clear");
            home_menu(2);
            getline(cin, input);
            ss << input;
            ss >> input;
            if(!is_number(input))
                continue;
            input_to_int = stoi(input);
        }while(input_to_int < 1 && input_to_int > 5);
        */
        system("clear");
        home_menu(2);
        cin >> input_to_int;

        switch (input_to_int)
        {
        case 1:
            if (user.withdraw())
                cout << "Withdraw successful!" << endl;
            else
                cout << "Withdraw failed!" << endl;
            sleep(2);
            break;
        case 2:
            if (user.deposit())
                cout << "Deposit successful!" << endl;
            else
                cout << "Deposit failed!" << endl;
            sleep(2);
            break;
        case 3:
            if (user.transfer())
                cout << "Transfer successful!" << endl;
            else
                cout << "Transfer failed!" << endl;
            sleep(2);
            break;
        case 4:
            Transaction::process_transactions();
            break;
        case 5:
            system("clear");
            return;
        default:
            break;
        }
        system("clear");
    }
}
