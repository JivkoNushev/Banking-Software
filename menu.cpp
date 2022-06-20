#include <iostream>
#include "menu.h"

void home_menu()
{
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
}

void signin_menu()
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

string print_menu()
{
    system("cls");
    uint8_t input = -1;

    home_menu();
    cin >> input;

    switch(input)
    {
        case 1:
            signin_menu();
            break;
        case 2:
            signup_menu();
            break;
        case 3:
            system("cls");
            cout << "Exited from the bank";
            return "";
    }
    system("cls");
    return ;
}
