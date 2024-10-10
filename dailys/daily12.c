/*
Author: Phi Nguyen
Date: 09/27/2024
Purpose:

Continually play games of rock-paper-scissor until  the user selects n. Check for incorrect inputs by the user and clear keyboard buffer after each input.

Time spent:

18 minutes


*/

#include <stdio.h>

void play_game(void);
char get_choice(void);
void clear_buffer(void);

int main(int argc, char *argv[])
{
    char c;
    int noc;
    do
    {
        play_game();
        printf("Do you wish to continue? (y/n): ");
        noc = scanf("%c", &c);
        clear_buffer();
    } while (c == 'y' || c == 'Y');
}

void play_game(void)
{
    char p1;
    char p2;
    printf("Player 1 it is your turn!\n");
    p1 = get_choice();
    printf("Player 2 it is your turn!\n");
    p2 = get_choice();

    if (((p1 == 'r' || p1 == 'R') && (p2 == 's' || p2 == 'S')) || ((p1 == 's' || p1 == 'S') && (p2 == 'r' || p2 == 'R')))
    {
        printf("Rock breaks Scissors.");
        if (p1 == 'r' || p1 == 'R')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if (((p1 == 's' || p1 == 'S') && (p2 == 'p' || p2 == 'P')) || ((p1 == 'p' || p1 == 'P') && (p2 == 's' || p2 == 'S')))
    {
        printf("Scissors cuts Paper.");
        if (p1 == 's' || p1 == 'S')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if (((p1 == 'p' || p1 == 'P') && (p2 == 'r' || p2 == 'R')) || ((p1 == 'r' || p1 == 'R') && (p2 == 'p' || p2 == 'P')))
    {
        printf("Paper eats Rock.");
        if (p1 == 'p' || p1 == 'P')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
    return;
}

char get_choice(void)
{
    char choice;
    int noc;
    printf("Player choose (r)ock, (p)aper, (s)cissors: ");
    noc = scanf("%c", &choice);
    clear_buffer();
    while (noc != 1 || choice != 'r' && choice != 'p' && choice != 's' && choice != 'R' && choice != 'P' && choice != 'S')
    {
        printf("I'm sorry but you must enter 'r', 'p', or 's'\n");
        printf("Player choose (r)ock, (p)aper, (s)cissors: ");
        noc = scanf("%c", &choice);
        clear_buffer();
    }
    return choice;
}

void clear_buffer(void)
{
    char ans = 's';
    while (ans != '\n')
    {
        scanf("%c", &ans);
    }
    return;
}