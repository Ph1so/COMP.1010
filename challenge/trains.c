#include <stdio.h>

int swap_train(int trains[], int length, int count);
int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);

    while (n != 0)
    {
        int length;
        scanf("%d", &length);
        int trains[length];
        int index = 0;
        while (index != length)
        {
            scanf("%d", &trains[index]);
            index++;
        }
        if (length == 1 || length == 0)
            printf("Optimal train swapping takes 0 swaps.\n");
        else
        {
            int count = swap_train(trains, length, 0);
            printf("Optimal train swapping takes %d swaps.\n", count);
        }
        n--;
    }
    return 0;
}

int swap_train(int trains[], int length, int count)
{
    int swapped = 0;
    int right = 1;
    while (swapped == 0)
    {
        int t_left = trains[right - 1];
        int t_right = trains[right];
        if (t_left > t_right) // swap if left > right
        {
            trains[right] = t_left;
            trains[right - 1] = t_right;
            swapped = 1; // swap then end loop -> recall function -> start at first index
            count += 1;
        }
        right++;
        if (right == length && swapped == 0) // if it reaches the end and no swaps are made then trains are in order
            return count;
    }
    return swap_train(trains, length, count); // uses new swapped trains and new count
}

// Take 1: the swapping only moves forward, it needs to constantly start from the first index and return if it reaches the end and no swaps are made
// int swap_train(int trains[], int right, int length, int count)
// {
//     int t_left = trains[right - 1];
//     int t_right = trains[right];
//     if (t_left > t_right)
//     {
//         trains[right] = t_left;
//         trains[right - 1] = t_right;
//         return swap_train(trains, right, length, count + 1);
//     }
//     else if (right != length - 1)
//     {
//         return swap_train(trains, right + 1, length, count);
//     }
//     else
//     {
//         return count;
//     }
// }