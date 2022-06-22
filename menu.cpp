#include "menu.h"
#include "user.h"
#include "transactions.h"
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
    string username, password;
    do
    {
        system("cls");
        
        cout << "|               Sign in                   |\n";
        
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
    } while(!User::user_exists(username, password));

    return User::user_id(username);
}

int signup_menu()
{
    string username, password;
    do
    {
        system("cls");
        
        cout << "|               Sign up                   |\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
    } while(User::username_exists(username));
    User user(username, password, User::generate_id(username));
    user.add_user();
    return user.get_id();
}

int print_home_menu()
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
                return 0;
            default:
        }
        system("cls");
    }
}

void menu(User &user)
{
    system("cls");
    uint8_t input = -1;
    
    queue<Transaction> queue;
    while(1)
    {
        home_menu(2);
        cin >> input;
        switch(input)
        {
            case 1:
                user.withdraw();
                break;
            case 2:
                user.deposit();
                break;
            case 3:
                user.transfer(&queue);
                break;
            case 4:
                Transaction::process_transaction(&queue);
                break;
            case 5:
                system("cls");
                return;
            default:
        }
        system("cls");
    }
}
