/***********************************************
Author: Phi Nguyen
Date: 10/29/2024
Purpose: This program prints out all number of steps to reach 1 given a range of numbers
***********************************************/

#include <stdio.h>

// Function prototypes
void calc_num_steps(int num);
int get_integer_input(const char* prompt);

int main(int argc, char* argv[])
{
    int start, end, num_column = 0;

    // Get range inputs with validation
    start = get_integer_input("Enter a starting point (positive integer): ");
    end = get_integer_input("Enter an ending point (greater than starting point): ");

    // Ensure the end is greater than start
    if (end <= start) {
        printf("Error: Ending point must be greater than starting point.\n");
        return 1;
    }

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
    printf("%d:", num);

    while (num != 1) {
        if (num % 2 == 0)
            num = num / 2;
        else
            num = 3 * num + 1;
        count++;
    }
    printf("%d\t\t", count);
}

// Function to get validated integer input within a positive range
int get_integer_input(const char* prompt) {
    int num;
    char buffer[20];

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            // Check if input is numeric and within integer range
            if (sscanf(buffer, "%d", &num) == 1 && num > 0) {
                return num;
            } else {
                printf("Invalid input. Please enter a positive integer.\n");
            }
        } else {
            printf("Input error. Please try again.\n");
        }
    }
}
