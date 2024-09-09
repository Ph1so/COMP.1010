/*
Name: Phi Nguyen
Date: 09/06/2024

Output:

cd "/Users/phinguyen/COMP1010/output"
./"daily2"
phinguyen@Phis-Air COMP1010 % cd "/Users/phinguyen/COMP1010/output"
phinguyen@Phis-Air output % ./"daily2"
This program has the executable name: ./daily2
That is all!
*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("This program has the executable name: %s\n", argv[0]);
    printf("That is all!\n");
    return 0;
}