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
    printf("%d is an integer and should be printed using %cd.\n", 42, 37);
    printf("The character '%c' can be printed using %cc.\n", 'J', 37);
    printf("Floating point numbers use %cf. %f is an example.\n", 37, 3.14159);
    return 0;
}