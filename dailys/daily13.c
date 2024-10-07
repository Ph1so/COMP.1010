/*
Author: Phi Nguyen
Date: 10/06/2024
Purpose:

Continually play games of rock-paper-scissor until  the user selects n. Check for incorrect inputs by the user and clear keyboard buffer after each input.

Time spent:

10 minutes


*/

#include <stdio.h>

enum choice
{
    ROCK,
    PAPER,
    SCISSOR
};

typedef enum choice Choice;

void play_game(void);
Choice get_choice(void);
void clear_buffer(void);

int main(int argc, char *argv[])
{
    char c;
    int noc;
    do
    {
        play_game();
        do
        {
            printf("Do you wish to continue? (y/n): ");
            noc = scanf("%c", &c);
            clear_buffer();
        } while (noc != 1 || (c != 'y' && c != 'n'));
    } while (c == 'y');
    return 0;
}

void play_game(void)
{
    Choice p1, p2;
    printf("Player 1, it is your turn!\n");
    p1 = get_choice();
    printf("Player 2, it is your turn!\n");
    p2 = get_choice();

    if ((p1 == ROCK && p2 == SCISSOR) || (p2 == ROCK && p1 == SCISSOR))
    {
        printf("Rock breaks Scissors.");
        if (p1 == ROCK)
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if ((p1 == SCISSOR && p2 == PAPER) || (p2 == SCISSOR && p1 == PAPER))
    {
        printf("Scissors cuts Paper.");
        if (p1 == SCISSOR)
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else if ((p1 == PAPER && p2 == ROCK) || (p2 == PAPER && p1 == ROCK))
    {
        printf("Paper covers Rock.");
        if (p1 == PAPER)
            printf(" Player 1 wins!\n");
        else
            printf(" Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

Choice get_choice(void)
{
    char choice;
    int noc;

    while (1)
    {
        printf("Player, choose (r)ock, (p)aper, (s)cissors: ");
        noc = scanf("%c", &choice);
        clear_buffer();

        if (noc == 1 && (choice == 'r' || choice == 'R'))
            return ROCK;
        else if (noc == 1 && (choice == 'p' || choice == 'P'))
            return PAPER;
        else if (noc == 1 && (choice == 's' || choice == 'S'))
            return SCISSOR;
        else
            printf("I'm sorry, I do not understand.\n");
    }
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
