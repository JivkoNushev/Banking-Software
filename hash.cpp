#include <iostream>
#include <string>
#include <stdint-gcc.h>
#include <string.h>
#include <byteswap.h>
#include "hash.h"
using namespace std;

void print_binary_number(uint8_t n)
{
    for (int i = 0; i < 8; i++)
    {
        if (n & 1)
            cout << 1;
        else
            cout << 0;
        n >>= 1;
    }
    cout << "-";
}
void print_binary_number(uint64_t n)
{
    for (int i = 0; i < 64; i++)
    {
        if (n & 1)
            cout << 1;
        else
            cout << 0;
        n >>= 1;
    }
    cout << "-";
}
void print(uint8_t *input, int size)
{
    for (int i = 0; i < size; i++)
    {
        print_binary_number(*input);
        input++;
    }
    cout << endl;
}

// TODO: little and big endian
int alo()
{
    char a[] = "abc";
    char *input = a;

    uint64_t length = strlen(input);
    int curr_block_length = 0;

    print_binary_number(length * 8);
    __builtin_bswap64(length);

    print_binary_number(length * 8);
    // 512 bits(64 bytes) blocks
    // 448 bits(56 bytes) of info and 64(8 bytes) for length of message
    cout << "Lenth: " << length << endl;
    if (length < 56)
    {
        char a[] = "abc";
        char *input = a;

        uint64_t length = strlen(input);
        int curr_block_length = 0;

        // 512 bits(64 bytes) blocks
        // 448 bits(56 bytes) of info and 64(8 bytes) for length of message

        // cout << "Lenth: " << length << endl;
        if (length < 56)
        {
            uint8_t block[64] = {0};
            for (int i = 0; i < length; i++)
            {
                block[i] = input[i];
            }

            curr_block_length += length;
            // cout << "ASCII to binary: " << endl;
            print(block, curr_block_length);

            // cout << "Add 1 between msg and padded 0s: " << endl;
            block[curr_block_length] = 128;
            curr_block_length++;
            print(block, curr_block_length);

            // cout << "Padd with 0s until 56 bytes: " << endl;
            curr_block_length = 56;
            print(block, curr_block_length);

            // cout << "after that add 8 bytes of length of bits: << endl;
            block[curr_block_length] = length * 8;
            curr_block_length = 64;
            print(block, curr_block_length);
        }
    }
}

string hash_string(string input)
{
    return input;
}