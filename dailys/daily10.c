/*
Author: Phi Nguyen
Date: 09/27/2024
Purpose:

Repeatedly ask the user to input a negative number until the user inputs a correct value.

Time spent:

8 minutes


*/

#include <stdio.h>

void clear_buffer(void);

int main(int argc, char *argv[])
{
    int answer;
    int noc;
    printf("Please enter a negative integer: ");
    noc = scanf("%d", &answer);

    while (noc != 1 || answer >= 0)
    {
        printf("I'm sorry, you must enter a negative integer less than zero: ");
        clear_buffer();
        noc = scanf("%d", &answer);
    }
    printf("The negative integer was: %d\n", answer);
    return 0;
}

void clear_buffer(void)
{
    int noc;
    char c;
    noc = scanf("%c", &c);
    while (c != '\n')
    {
        noc = scanf("%c", &c);
    }
    return;
}