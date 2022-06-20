#include <iostream>
#include "menu.h"
#include "dataTypes.h"

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

string signin_menu()
{
    do
    {
        system("cls");
        
        cout << "|               Sign in                   |\n";
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
    } while(!user_exists(username, password));

    return user_id(username);
}

string signup_menu()
{
    do
    {
        system("cls");
        
        cout << "|               Sign up                   |\n";
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
    } while(username_exists(username));
    return add_user(username, password); // returns id
}

string print_home_menu()
{
    system("cls");
    uint8_t input = -1;
    
    while(1)
    {
        home_menu(1);
        cin >> input;
        switch(input)
        {
            case 1:
                return signin_menu();
            case 2:
                return signup_menu();
            case 3:
                system("cls");
                cout << "Exited from the bank";
                return "";
            default:
        }
        system("cls");
    }
}

void menu(User *user)
{
    system("cls");
    uint8_t input = -1;

    while(1)
    {
        home_menu(2);
        cin >> input;
        switch(input)
        {
            case 1:
                withdraw();
                break;
            case 2:
                deposit();
                break;
            case 3:
                transfer();
                break;
            case 4:
                transactions();
                break;
            case 5:
                system("cls");
                return;
            default:
        }
        system("cls");
    }
}
