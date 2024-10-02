#include <stdio.h>

int break_coins(int total, int options);

int main(int argc, char *argv[])
{
    int options = break_coins(25, 0);
    printf("%d", options);
    return 0;
}

int break_coins(int total, int options)
{
    total = total / 5;
    options += total + 1;
    if (total > 1)
    {
        total = total / 2;
        options += total + 1 + break_coins(5 * (total % 2), 0);
    }
    if (total > 2)
    {
        total = total / 2.5;
        options += total + 1 + break_coins(5 * 2.5 * (total % 2.5), 0);
    }
    return options;
}

// Take 2: calls break_coins after taking largest possible coin - doesnt break the rest
// int break_coins(int total, int options)
// {
//     while (total >= 5)
//     {
//         if (total >= 50)
//         {
//             total -= 50;
//             options += 1 + break_coins(total, 0);
//         }
//         else if (total >= 25)
//         {
//             total -= 25;
//             options += 1 + break_coins(total, 0);
//         }
//         else if (total >= 10)
//         {
//             total -= 10;
//             options += 1 + break_coins(total, 0);
//         }
//         else if (total >= 5)
//         {
//             total -= 5;
//             options += 1 + break_coins(total, 0);
//         }
//     }
//     return options;
// }

// Take 1: if the remainder is 0, it gets stuck and infinitly loops - break total into all LARGEST coins, then break each LARGEST coin induvidually until the total < 5
// int break_coins(int total, int options)
// {
//     int coins[] = {50, 25, 10, 5, 1};
//     int coin = 0;
//     int found_break = 0;
//     if (total < 5)
//     {
//         return options;
//     }
//     while (found_break == 0)
//     {
//         if (coins[coin] <= total)
//         {
//             printf("break: %d\n", total);
//             return 1 + total / coins[coin] * break_coins(total - total % coins[coin], options);
//             found_break = 1;
//         }
//         coin++;
//     }
// }