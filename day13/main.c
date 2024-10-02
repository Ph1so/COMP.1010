#include <stdio.h>

enum suit
{
    HEARTS = 5,
    DIAMONDS,
    CLUBS,
    SPADES
};

typedef enum suit Suit;

struct card
{
    Suit suit;
    int rank;
};

typedef struct card Card;

int main(int argc, char *argv[])
{
    Card my_card;
    return 0;
}