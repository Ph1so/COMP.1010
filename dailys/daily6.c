/*
Author: Phi Nguyen
Date: 09/16/2024
Answer to question:

Segmentation fault error occurs. This could be a form of stack overflow where the program uses more memory than allocated.
In this case, the number 500000 was too big and the recursion functions used too much memory.

*/

#include <stdio.h>

void recursive_down_to_zero(int number);
void recursive_up_to_int(int number);

int main(int argc, char *argv[])
{
    recursive_down_to_zero(10);
    printf("****\n");
    recursive_up_to_int(10);
    return 0;
}

void recursive_down_to_zero(int number)
{
    if (number > 0)
    {
        printf("%d\n", number);
        recursive_down_to_zero(number - 1);
    }
    return;
}

void recursive_up_to_int(int number)
{
    if (number > 0)
    {
        recursive_up_to_int(number - 1);
        printf("%d\n", number);
    }
    return;
}