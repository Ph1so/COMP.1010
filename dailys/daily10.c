/*
Author: Phi Nguyen
Date: 09/27/2024
Answer to the question:

Printing many times does not cause a stack overflow like recursion did with large numbers because
printing does not use a frame of memory and it does not stack like the recursion did. The recurison in daily6
kept stacking frames because each function call could not be complete until the very last function call returned.
Thus, each function call added to the stack in memory, eventually causing a stack overflow. Printing does not
follow the same nature of stacking because it is a SINGLE function call.

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