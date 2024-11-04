/***********************************************
Author: Phi Nguyen
Date: 11/3/2024
Purpose: Practice top down approach using stub functions. simulate getting user repsonse and converting input in length or weight based off user response
Resources: NA
Time Spent: 5 minutes
***********************************************/

#include <stdio.h>

void convert_lengths(int *p_length);
void convert_weights(int *p_weight);
void get_input(int *p_ans);
void clear_buffer(void);
void get_num(int *p_num);
void length_to_metric(int* p_length);
void length_to_us(int* p_length);
void weight_to_metric(int* p_weight);
void weight_to_us(int* p_weight);

int main(int argc, char *argv[])
{
    int ans;
    int num;
    do
    {
        get_input(&ans);
        switch (ans)
        {
        case 1:
            convert_lengths(&num);
            break;
        case 2:
            convert_weights(&num);
            break;
        }

    } while (ans != 0);

    return 0;
}

void convert_lengths(int *p_length)
{
    int input;
    int noc;
    do
    {
        printf("Convert from feet/inches to meters/centimeters (input value of 1) or from meters/centimeters to feet/inches (input value of 2) or exit (input value of 0): ");
        noc = scanf("%d", &input);
        clear_buffer();
    } while (noc != 1 || !(input >= 0 && input <= 3));
    switch (input)
    {
        case 0:
            return;
        case 1:
            length_to_metric(p_length);
            break;
        case 2:
            length_to_us(p_length);    
            break;
    }
    return;
}
void convert_weights(int *p_weight)
{
    int input;
    int noc;
    do
    {
        printf("Convert  from pounds/ounces to kilograms/grams (input value of 1) or from kilograms/grams to pounds/ounces (input value of 1)) or exit (input value of 0): ");
        noc = scanf("%d", &input);
        clear_buffer();
    } while (noc != 1 || !(input >= 0 && input <= 3));
    switch (input)
    {
        case 0:
            return;
        case 1:
            weight_to_metric(p_weight);
            break;
        case 2:
            weight_to_us(p_weight);    
            break;
    }
    return;
}

void get_input(int *p_ans)
{
    int noc;
    do
    {
        printf("Enter choice (0 - Exit, 1 - Convert Length, 2 - Convert Weight): ");
        noc = scanf("%d", p_ans);
        clear_buffer();
    } while (noc != 1 || (*p_ans != 0 && *p_ans != 1 && *p_ans != 2));
    return;
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

void get_num(int *p_num)
{
    printf("enter weight or length: ");
    scanf("%d", p_num);
}

void length_to_metric(int * p_length){
    printf("length to metric\n");
    return;
}

void length_to_us(int * p_length){
    printf("length to us\n");
    return;
}

void weight_to_metric(int * p_weight){
    printf("weight to metric\n");
    return;
}

void weight_to_us(int * p_weight){
    printf("weight to us\n");
    return;
}