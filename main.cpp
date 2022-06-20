#include <iostream>
#include "dataTypes.h"
#include "menu.h"

using namespace std;

int main(int argc, char** argv)
{
    int input = -1;

    while(1)
    {

        login_menu();
        cin >> input;
        if(input == 3) break;
        system("cls");
    }
    system("cls");
    cout << "Exited from the bank";
    printf("alo da");
    return 0;
}