#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    while (count < 10)
    {
        printf("%d", count);
        count += 1;
    }
    return 0;
}