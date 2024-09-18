#include <stdio.h>

void towers(int discs, int from, int to, int spare);

int main(int argc, char *argv[])
{
    towers(3, 1, 3, 2); // move 3 disks from rod 1 to rod 3 with 2 to spare (arguments)
    return 0;
}

void towers(int discs, int from, int to, int spare)
{
    if (discs > 0)
    {
        towers(discs - 1, from, spare, to);
        printf("move disc %d from peg %d to %d\n", discs, from, to);
        towers(discs - 1, spare, to, from);
    }
}