#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//currently c code

/*PRINT*/
void print_binary_number(int n)
{
    for (int c = 7; c >= 0; c--)
    {
        if (n >> c & 1)
            printf("1");
        else
            printf("0");
    }
    printf("-");
}
void print(char* input, int size)
{
    for (int i = 0; i < size; i++)
    {
        print_binary_number(*input);
        input++;
    }
}

string hash_string(string input)
{
    char input1[] = "abc";
    char *input_string = input1;
    int input_len = strlen(input_string),
        blocks = input_len/64;

    char *block = (char*)malloc(64);
    if (!block) return 0;
    memset(block, 0, 64);
    char null = 128;

    for (int i = 0; i <= blocks; i++)
    {
        if(input_len>=56)
            memcpy(block, input_string, 56);
        else
        {
            memcpy(block, input_string, input_len);
            memcpy(block+input_len, &null, sizeof(null));
        }
        unsigned long long len = 1;

        memcpy(block + 56, &len, 8);

        print(block,64);

        //hash
       
        input_string += 64;
        input_len -= 64;

        memset(block, 0, 64);
    }
}