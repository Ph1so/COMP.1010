/***********************************************
Author: Phi Nguyen
Date: 10/29/2024
Purpose: Practice top down approach using stub functions. simulate getting user repsonse and converting input in length or weight based off user response
Resources: NA
Time Spent: 10 minutes
***********************************************/

#include <stdio.h>

void convert_lengths(int* p_length);
void convert_weights(int* p_weight);
void get_input(int* p_ans);
void clear_buffer(void);
void get_num(int* p_num);

int main(int argc, char*argv[])
{
    int ans;
    int num;
    do
    {
        get_input(&ans);
        switch(ans)
        {
            case 1:
                get_num(&num);
                convert_lengths(&num);
                break;
            case 2:
                get_num(&num);
                convert_weights(&num);
                break;
        }
            
    } while (ans != 0);
    
    return 0;
}

void convert_lengths(int* p_length)
{
    printf("convert length %d\n", *p_length);
    return;
}
void convert_weights(int* p_weight)
{
    printf("convert weight %d\n", *p_weight);
    return;
}

void get_input(int* p_ans)
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

void get_num(int* p_num)
{
    printf("enter weight or length: ");
    scanf("%d", p_num);
}