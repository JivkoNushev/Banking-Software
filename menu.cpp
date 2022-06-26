#include <fstream>
#include <iostream>
#include <sstream>

#include "menu.h"
#include "hash.h"
#include "user.h"
#include "transaction.h"
using namespace std;

void home_menu(int number)
{
    switch(number)
    {
        case 1:
            cout << 
    "+----------------------------------------+\n"\
    "|               Home menu                |\n"\
    "| 1.Sign in                              |\n"\
    "| 2.Sign up                              |\n"\
    "| 3.Exit                                 |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "+----------------------------------------+\n";
        break;
        case 2:
            cout << 
    "+----------------------------------------+\n"\
    "|               Home menu                |\n"\
    "| 1.Withdraw                             |\n"\
    "| 2.Deposit                              |\n"\
    "| 3.Transfer                             |\n"\
    "| 4.Transactions                         |\n"\
    "| 5.Logout                               |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "|                                        |\n"\
    "+----------------------------------------+\n";
        break;    
    }
    
}

int signin_menu()
{
    string username = "", password = "";
    do
    {
        system("clear");
        
        cout << "|               Sign in                   |\n";
        
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
    } while(!User::user_exists(username, password));

    return User::user_id(username);
}

int signup_menu()
{
    string username = "", password = "";

    do
    {
        system("clear");
        
        cout << "|               Sign up                   |\n";
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        password = hash_string(password);
    } while(User::username_exists(username));
    User user(username, password, User::generate_id(username));
    user.add_user();

    return user.get_id();
}

bool isNumber(const string& s)
{
    for (char const &ch : s) {
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
    while(1)
    {
        do
        {
            system("clear");
            home_menu(1);
            getline(cin, input);
            ss << input;
            ss >> input;
            if(!isNumber(input))
                continue;
            input_to_int = stoi(input);
        }while(input_to_int < 1 && input_to_int > 3);

        switch(input_to_int)
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
    
    while(1)
    {
        do
        {
            system("clear");
            home_menu(2);
            getline(cin, input);
            ss << input;
            ss >> input;
            if(!isNumber(input))
                continue;
            input_to_int = stoi(input);
        }while(input_to_int < 1 && input_to_int > 5);

        switch(input_to_int)
        {
            case 1:
                user.withdraw();
                break;
            case 2:
                user.deposit();
                break;
            case 3:
                user.transfer();
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
