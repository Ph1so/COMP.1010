/***********************************************
 Program: Daily16 Conversion Program
 Author: Phi Nguyen
 Date: 11/3/2024
 Time Spent: 30 minutes
 Sources of Help: None
 Purpose: Practice top-down approach with stub functions, 
 separating input, conversion, and output functions, and using pointers.
***********************************************/

#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void get_input(int *p_ans);
void clear_buffer(void);

void length_to_metric(void);
void length_input_us(int *feet, double *inches);
void length_convert_to_metric(int feet, double inches, int *meters, double *centimeters);
void length_output_metric(int meters, double centimeters);

void length_to_us(void);
void length_input_metric(double *meters, double *centimeters);
void length_convert_to_us(double meters, double centimeters, int *feet, double *inches);
void length_output_us(int feet, double inches);

void weight_to_metric(void);
void weight_input_us(int *pounds, double *ounces);
void weight_convert_to_metric(int pounds, double ounces, int *kilograms, double *grams);
void weight_output_metric(int kilograms, double grams);

void weight_to_us(void);
void weight_input_metric(double *kilograms, double *grams);
void weight_convert_to_us(double kilograms, double grams, int *pounds, double *ounces);
void weight_output_us(int pounds, double ounces);

int main(int argc, char *argv[])
{
    int ans;
    do
    {
        get_input(&ans);
        switch (ans)
        {
        case 1:
            convert_lengths();
            break;
        case 2:
            convert_weights();
            break;
        }
    } while (ans != 0);

    return 0;
}

void convert_lengths(void)
{
    int choice;
    do
    {
        printf("Convert from feet/inches to meters/centimeters (input 1) or from meters/centimeters to feet/inches (input 2) or exit (input 0): ");
        scanf("%d", &choice);
        clear_buffer();
    } while (choice < 0 || choice > 2);

    if (choice == 1)
        length_to_metric();
    else if (choice == 2)
        length_to_us();
}

void convert_weights(void)
{
    int choice;
    do
    {
        printf("Convert from pounds/ounces to kilograms/grams (input 1) or from kilograms/grams to pounds/ounces (input 2) or exit (input 0): ");
        scanf("%d", &choice);
        clear_buffer();
    } while (choice < 0 || choice > 2);

    if (choice == 1)
        weight_to_metric();
    else if (choice == 2)
        weight_to_us();
}

void get_input(int *p_ans)
{
    int noc;
    do
    {
        printf("Enter choice (0 - Exit, 1 - Convert Length, 2 - Convert Weight): ");
        noc = scanf("%d", p_ans);
        clear_buffer();
    } while (noc != 1 || (*p_ans < 0 || *p_ans > 2));
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

// Length Conversion Functions
void length_to_metric(void)
{
    int feet, meters;
    double inches, centimeters;

    length_input_us(&feet, &inches);
    length_convert_to_metric(feet, inches, &meters, &centimeters);
    length_output_metric(meters, centimeters);
}

void length_input_us(int *feet, double *inches)
{
    printf("Enter feet: ");
    scanf("%d", feet);
    printf("Enter inches: ");
    scanf("%lf", inches);
}

void length_convert_to_metric(int feet, double inches, int *meters, double *centimeters)
{
    double total_inches = feet * 12 + inches;
    double total_meters = total_inches * 0.3048/12;
    *meters = (int)total_meters;
    *centimeters = (total_meters - *meters) * 100;
}

void length_output_metric(int meters, double centimeters)
{
    printf("Converted length: %d meters and %.2f centimeters\n", meters, centimeters);
}

void length_to_us(void)
{
    double meters, centimeters;
    int feet;
    double inches;

    length_input_metric(&meters, &centimeters);
    length_convert_to_us(meters, centimeters, &feet, &inches);
    length_output_us(feet, inches);
}

void length_input_metric(double *meters, double *centimeters)
{
    printf("Enter meters: ");
    scanf("%lf", meters);
    printf("Enter centimeters: ");
    scanf("%lf", centimeters);
}

void length_convert_to_us(double meters, double centimeters, int *feet, double *inches)
{
    double total_feet = (meters + centimeters/100)/0.3048;
    *feet = (int)(total_feet);
    *inches = 12*(total_feet - *feet);
}

void length_output_us(int feet, double inches)
{
    printf("Converted length: %d feet and %.2f inches\n", feet, inches);
}

// Weight Conversion Functions
void weight_to_metric(void)
{
    int pounds, kilograms;
    double ounces, grams;

    weight_input_us(&pounds, &ounces);
    weight_convert_to_metric(pounds, ounces, &kilograms, &grams);
    weight_output_metric(kilograms, grams);
}

void weight_input_us(int *pounds, double *ounces)
{
    printf("Enter pounds: ");
    scanf("%d", pounds);
    printf("Enter ounces: ");
    scanf("%lf", ounces);
}

void weight_convert_to_metric(int pounds, double ounces, int *kilograms, double *grams)
{
    double total_pounds = pounds + ounces/16;
    double total_kilograms = total_pounds / 2.2046;
    *kilograms = (int)total_kilograms;
    *grams = (total_kilograms - *kilograms) * 1000;
}

void weight_output_metric(int kilograms, double grams)
{
    printf("Converted weight: %d kilograms and %.2f grams\n", kilograms, grams);
}

void weight_to_us(void)
{
    double kilograms, grams;
    int pounds;
    double ounces;

    weight_input_metric(&kilograms, &grams);
    weight_convert_to_us(kilograms, grams, &pounds, &ounces);
    weight_output_us(pounds, ounces);
}

void weight_input_metric(double *kilograms, double *grams)
{
    printf("Enter kilograms: ");
    scanf("%lf", kilograms);
    printf("Enter grams: ");
    scanf("%lf", grams);
}

void weight_convert_to_us(double kilograms, double grams, int *pounds, double *ounces)
{
    double total_pounds = (kilograms + grams/1000)*2.2046;
    *pounds = (int)(total_pounds);
    *ounces = 16*(total_pounds - *pounds);
}

void weight_output_us(int pounds, double ounces)
{
    printf("Converted weight: %d pounds and %.2f ounces\n", pounds, ounces);
}
