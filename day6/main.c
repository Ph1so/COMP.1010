#include <stdio.h>

int joe(int);

int main()
{
    joe(3);
    return 0;
}

int joe(int x)
{
    if (x > 0)
    {
        printf("%d", x);
        joe(x - 1);
    }
    return 0;
}