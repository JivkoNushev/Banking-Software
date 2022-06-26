#include "hash.h"
using namespace std;

unsigned int hash_to_uint(string input)
{
    unsigned int random = 492088, hash;
    for (int i = 0; i < input.length(); i++)
    {
        hash ^= input[i];
        hash *= random;
    }
    return hash;    
}
string hash_string(string input)
{
    unsigned int hashed = hash_to_uint(input);
    return to_string(hashed);
}