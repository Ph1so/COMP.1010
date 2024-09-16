#include <stdio.h>

void joe(void)
{
    printf("Hello from joe\n");
    joe(); // recursion - infinite - causes "stack overflow"
    return;
}

int main(int argc, char *argv[])
{
    printf("Hello from main\n");
    joe();
    return 0;
}