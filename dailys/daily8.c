/*
Author: Phi Nguyen
Date: 09/20/2024
Purpose:

The purpose of the program is to get a user's input and modify its value based on whether or not it is even.
I use & to denote where in memory do I want to assign the user's input, which is at the varible `number`
Then do a calculation based on the input, and print.

*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int number;
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    if (number % 2 == 0)
    {
        number = number / 2;
    }
    else
    {
        number = number * 3 + 1;
    }
    printf("The next value of the number is: %d\n", number);
    return 0;
}