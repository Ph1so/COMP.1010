/*
Author: Phi Nguyen
Date: 09/14/2024
Output:
  XXXX
 X . .X
X      X
X  \_/ X
 X    X
  XXXX

  XXXX
 X . .X
X      X
X  \_/ X
 X    X
  XXXX

  XXXX
 X . .X
X      X
X  \_/ X
 X    X
  XXXX
*/

#include <stdio.h>

void smile(void)
{
    printf("  XXXX   \n");
    printf(" X . .X \n");
    printf("X      X\n");
    printf("X  \\_/ X\n");
    printf(" X    X \n");
    printf("  XXXX   \n");
    return;
}

int main(int argc, char *argv[])
{
    smile();
    printf("\n");
    smile();
    printf("\n");
    smile();
    return 0;
}