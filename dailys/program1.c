/***********************************************
Author: Phi Nguyen  
Date: 10/29/2024  
Purpose: This program prints out all number of steps to reach 1 given a range of numbers  
***********************************************/  

#include <stdio.h>  

// Function prototypes  
void calc_num_steps(int num);  
int get_integer_input(const char* prompt, int min, int max);  

int main(int argc, char* argv[])  
{  
    int start, end, num_column = 0;  

    // Get range inputs with validation  
    start = get_integer_input("Enter a starting point (1 < start < 1000): ", 2, 999);  
    end = get_integer_input("Enter an ending point (start < end < 10000): ", start + 1, 9999);  

    // Print steps for each number in the range  
    for (int i = start; i <= end; i++) {  
        if (num_column == 7) { // New line after every 7 columns  
            printf("\n");  
            num_column = 0;  
        }  
        calc_num_steps(i);  
        num_column++;  
    }  
    printf("\n"); // Final newline for neatness  
    return 0;  
}  

// Calculate the number of steps to reach 1 and print formatted output  
void calc_num_steps(int num) {  
    int count = 0;  
    printf("%5d: ", num);  

    while (num != 1) {  
        if (num % 2 == 0)  
            num = num / 2;  
        else  
            num = 3 * num + 1;  
        count++;  
    }  
    printf("%-5d", count);  
}  

// Function to get validated integer input within a specific range  
int get_integer_input(const char* prompt, int min, int max) {  
    int num;
    int noc;

    while (1) {  
        printf("%s", prompt);  
        noc = scanf("%d", &num);
        if (noc) {  
            // Check if input is numeric and within the specified range  
            if (num >= min && num <= max) {  
                return num;  
            } else {  
                printf("Invalid input. Please enter a number between %d and %d.\n", min, max);  
            }  
        } else {  
            printf("Input error. Please try again.\n");  
        }  
    }  
}  
