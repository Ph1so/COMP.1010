#include <stdio.h>

int main(int agrc, char *argv[])
{
    int x = 0;
    do
    {
        x++;
        printf("%d", x);
    } while (x > 0);
}