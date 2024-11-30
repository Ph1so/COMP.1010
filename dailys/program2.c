/***********************************************
Author: Phi Nguyen
Date: 11/15/2024
Purpose: Practice using pointers and top down approach
Resources: NA
Time Spent: 15 minutess
***********************************************/

#include <stdio.h>

void get_size(int* psize);
void get_days(int* pdays);
void calculate_population(int size, int days);
void get_choice(int* choice);
void clear_buffer(void);

int main(void){
    int choice, size, days;
    do{
        get_size(&size);
        get_days(&days);
        calculate_population(size, days);
        get_choice(&choice);
    }while(choice != 0);
    return 0;
}

void get_size(int* psize){
    int noc;
    while(1)
    {
        printf("Enter initial population size (non-negative integer): ");
        noc = scanf("%d", psize);
        clear_buffer();
        if (noc != 1 || *psize < 0) {
            printf("Invalid input. Please enter a non-negative integer.\n");
        }
        else
            break;
    }
}

void get_days(int* pdays){
    int noc;
    while(1)
    {
        printf("Enter number of days (non-negative integer): ");
        noc = scanf("%d", pdays);
        clear_buffer();
        if (noc != 1 || *pdays < 0) {
            printf("Invalid input. Please enter a non-negative integer.\n");
        }
        else
            break;
    }
}
void calculate_population(int size, int days){
    int num_fibs = days/5 + 1, i, day1 = size, day2 = 0, temp;
    for(i = 0; i < num_fibs; i++){
        temp = day2;
        day2 += day1;
        day1 = temp;
    }
    printf("Final population: %d\n", day2);
}
void get_choice(int* choice){
    int noc;
    while(1)
    {
        printf("Do you want to calculate again? Enter 1 for Yes or 0 for No: ");
        noc = scanf("%d", choice);
        clear_buffer();
        if (noc != 1 || (*choice != 0 && *choice != 1)) {
            printf("Invalid input. Please enter 1 for Yes or 0 for No.\n");
        }
        else
            break;
    }
}

void clear_buffer(void){
    char a; 
    do{
        scanf("%c", &a);
    }while(a != '\n');
}