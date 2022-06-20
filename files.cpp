#include <fstream>
#include <iostream>
#include "files.h"
#include "dataTypes.h"
using namespace std;

bool username_exists(string username)
{
    ifstream file;
	file.open("Database.txt", ios::in);

	User current_user;

	file.read((char*)&current_user, sizeof(current_user));
    do
	{
		if (current_user.get_name() == username)
			return true;
	    file.read((char*)&current_user, sizeof(current_user));
	} while (!file.eof());
    return false;
}

