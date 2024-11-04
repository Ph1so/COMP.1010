/***********************************************
Author: Phi Nguyen
Date: 10/29/2024
Purpose: This program prints out all number of steps to reach 1 given a range of numbers
Time Spent: 6 minutes
***********************************************/

#include <stdio.h>

void calc_num_steps(int num);

int main(int argc, char* argv[])
{
    // get range
    int start, end, num_column = 0;
    printf("Enter a starting point: ");
    scanf("%d", &start);
    printf("Enter an ending point: ");
    scanf("%d", &end);

    for(int i = start; i <= end; i++){
        if(num_column == 7){
            printf("\n");
            num_column = 0;
        }
        calc_num_steps(i);
        num_column++;
    }
    return 0;
}

void calc_num_steps(int num){
    int count = 0;
    printf("%d:", num);
    while(num != 1){
        if(num%2 == 0)
            num = num/2;
        else
            num = 3*num + 1;
        count++;
    }
    printf("%d\t", count);
}