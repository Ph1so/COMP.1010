#include <stdio.h>

int chop_trees(int trees[], int length);
int check_length(int trees[], int length); // return -1 if trees not in order

int main(int argc, char *argv[])
{
    int length;
    int height;
    scanf("%d", &length);
    int trees[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &height);
        trees[i] = height;
    }
    printf("%d\n", chop_trees(trees, length));
    return 0;
}

int chop_trees(int trees[], int length)
{
    int check = 0;
    int index = 1;
    int current = trees[0];
    while (check != -1 && index < length)
    {
        if (current > trees[index])
            check = -1;
        if (index > 0)
        {
            int new_trees[length - 1];
            int i = 0;
            int n = 0;
            while (i < length)
            {
                if (n != index)
                {
                    new_trees[i] = trees[i];
                }
                else
                {
                    i--;
                }
                i++;
                n++;
            }
        }
        else
        {
            check++;
            current = trees[index];
        }
        index++;
    }
    return check;
}

int check_length(int trees[], int length)
{
    int check = 0;
    int index = 1;
    int current = trees[0];
    while (check != -1 && index < length)
    {
        if (current > trees[index])
            check = -1;
        else
        {
            check++;
            current = trees[index];
        }
        index++;
    }
    return check;
}