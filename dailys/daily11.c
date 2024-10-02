/*
Author: Phi Nguyen
Date: 09/27/2024
Purpose:

Repeatedly ask the user to input a number within 1-79 until the user inputs a correct value.
Then print number of asterisks that the user input.

Time spent:

8 minutes


*/
#include <stdio.h>

void clear_buffer(void);

int main(int argc, char *argv[])
{
    int num;
    printf("Please enter the number of astrisks you want in your line: ");
    scanf("%d", &num);

    while (num <= 1 || num >= 79)
    {
        printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: ");
        clear_buffer();
        scanf("%d", &num);
    }

    while (num != 0)
    {
        printf("*");
        num--;
    }
    printf("\n");
    return 0;
}

void clear_buffer(void)
{
    char ans;
    scanf("%c", &ans);
    while (ans != '\n')
    {
        scanf("%c", &ans);
    }
    return;
}