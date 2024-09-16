/*
Author: Phi Nguyen
Date: 09/12/2024
Output:

42 is an integer and should be printed using %d.
The character 'J' can be printed using %c.
Floating point numbers use %f. 3.141590 is an example.

*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d is an integer and should be printed using %%d.\n", 42);
    printf("The character '%c' can be printed using %%c.\n", 'J');
    printf("Floating point numbers use %%f. %f is an example.\n", 3.14159);
    return 0;
}