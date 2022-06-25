#ifndef MENU
#define MENU

#include <string>
#include "user.h"
using namespace std;

void print_menu(User &user);
int print_home_menu();
int signup_menu();
int signin_menu();
void home_menu(int number);

#endif