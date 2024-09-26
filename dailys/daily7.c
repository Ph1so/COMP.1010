/*
Author: Phi Nguyen
Date: 09/18/2024
Purpose:

This program recursively converts a decimal number to its binary form.
It does so by processing half of the decimal number, reducing the task size, and then printing the corresponding binary digit.

*/
#include <stdio.h>

void add_digit(int decimal);

int main(int argc, char *argv[])
{
    add_digit(11);
    return 0;
}

void add_digit(int decimal)
{
    if (decimal == 0)
    {
        printf("0");
        return;
    }
    if (decimal > 1)
    {
        add_digit(decimal / 2);
    }
    printf("%d", decimal % 2);
}
