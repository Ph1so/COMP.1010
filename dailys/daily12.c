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
        printf("Do you wish to continue? (y/n) : ");
        noc = scanf("%c", &c);
        clear_buffer();
    } while (noc != 1 || c != 'y' && c != 'n');
    return 0;
}

void play_game(void)
{
    char p1;
    char p2;
    printf("Player 1 it is your turn!\n");
    p1 = get_choice();
    printf("Player 2 it is your turn!\n");
    p2 = get_choice();

    if ((p1 == 'r' && p2 == 's') || (p2 == 'r' && p1 == 's'))
    {
        printf("Rock breaks Scissors.");
        if (p1 == 'r')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if ((p1 == 's' && p2 == 'p') || (p2 == 's' && p1 == 'p'))
    {
        printf("Scissors cuts Paper.");
        if (p1 == 's')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if ((p1 == 'p' && p2 == 'r') || (p2 == 'p' && p1 == 'r'))
    {
        printf("Paper eats Rock.");
        if (p1 == 'p')
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    return;
}

char get_choice(void)
{
    char choice;
    int noc;
    printf("Player choose (r)ock, (p)aper, (s)cissors: ");
    noc = scanf("%c", &choice);
    clear_buffer();
    while (noc != 1 || choice != 'r' && choice != 'p' && choice != 's')
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