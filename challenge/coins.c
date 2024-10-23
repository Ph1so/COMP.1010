#include <stdio.h>

int break_coins(int total, int largest_coin);
int found[10000][5];
int main(int argc, char *argv[])
{
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 5; j++){
            found[i][j] = -1;
        }
    }
    int options = break_coins(7000, 50);
    printf("%d", options);
    return 0;
}

int break_coins(int total, int largest_coin) {
    // if the total is 0, there is only one way to break it
    if (total == 0) {
        return 1;
    }

    // If total is negative, no valid solution
    if (total < 0) {
        return 0;
    }

    int options = 0;
    int seen;
    // Recursively check all coins smaller than or equal to largest_coin
    if (largest_coin >= 50) {
        if(found[total-50][4] != -1){
            options += found[total-50][4];
        }
        else{
            seen = break_coins(total-50, 50);
            options += seen;
            found[total-50][4] = seen;
        }
    }
    if (largest_coin >= 25) {
        if(found[total-25][3] != -1){
            options += found[total-25][3];
        }
        else{
            seen = break_coins(total-25, 25);
            options += seen;
            found[total-25][3] = seen;
        }
    }
    if (largest_coin >= 10) {
        options += break_coins(total - 10, 10);  // Use a dime
    }
    if (largest_coin >= 5) {
        options += break_coins(total - 5, 5);    // Use a nickel
    }
    if (largest_coin >= 1) {
        options += 1;    // Use a penny
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