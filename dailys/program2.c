/***********************************************
Author: Phi Nguyen
Date: 11/15/2024
Purpose: Practice using pointers and top down approach
Resources: NA
Time Spent: 15 minutess
***********************************************/

#include <stdio.h>

void get_size(int* psize);
//Pre: none
//Post: The value pointed to by psize contains a non-negative integer entered by the user
void get_days(int* pdays);
//Pre: none 
//Post: The value pointed to by pdays contains a non-negative integer entered by the user.
void calculate_population(int size, int days);
//Pre: size is a non-negative integer representing the initial population size. days is a non-negative integer representing the number of days for the calculation.
//Post: Prints the calculated population at the end of the given number of days based on the Fibonacci-like growth pattern.
void get_choice(int* choice);
//Pre: none
//Post: The value pointed to by choice is set to 1 (to continue) or 0 (to exit) based on user input.
void clear_buffer(void);
//Pre: none
//Post: Clears the input buffer to discard any remaining characters, ensuring future input operations are clean. 

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