/*
Author: Phi Nguyen
Date: 09/23/2024
Answer to the question:

Printing many times does not cause a stack overflow like recursion did with large numbers because
printing does not use a frame of memory and it does not stack like the recursion did. The recurison in daily6
kept stacking frames because each function call could not be complete until the very last function call returned.
Thus, each function call added to the stack in memory, eventually causing a stack overflow. Printing does not
follow the same nature of stacking because it is a SINGLE function call.

*/

#include <stdio.h>
void loop_down_to_zero(int num);
void loop_up_to_int(int num);

int main(int argc, char *argv[])
{
    int number;
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    loop_down_to_zero(number);
    printf("****\n");
    loop_up_to_int(number);
    return 0;
}

void loop_down_to_zero(int num)
{
    while (num != 0)
    {
        printf("%d\n", num);
        num--;
    }
    return;
}
void loop_up_to_int(int num)
{
    int count = 0;
    while (count <= num)
    {
        printf("%d\n", count);
        count++;
    }
    return;
}