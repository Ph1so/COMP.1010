#include <stdio.h>
#include <ctype.h>

// Constants
#define FEET_TO_INCHES 12
#define INCHES_IN_FOOT 12
#define POUNDS_IN_KILOGRAMS 2.2046
#define METERS_IN_FOOT 0.3048
#define OUNCES_IN_POUND 16
#define GRAMS_IN_KILOGRAM 1000

// Function declarations
void convert_lengths(void);
// Pre: None. The program has already decided to handle length conversions.
// Post: Prompts the user for the direction of length conversion (ft/in to m/cm or m/cm to ft/in). 
//       Executes the appropriate conversion based on user input.

void convert_weights(void);
// Pre: None. The program has already decided to handle weight conversions.
// Post: Prompts the user for the direction of weight conversion (lb/oz to kg/g or kg/g to lb/oz). 
//       Executes the appropriate conversion based on user input.

void get_input(int *p_ans);
// Pre: Pointer to an integer is provided to store the user's choice.
// Post: Prompts the user for the main menu selection (0 - Exit, 1 - Convert Length, 2 - Convert Weight). 
//       Stores the valid user input in the variable pointed to by p_ans.

void clear_buffer(void);
// Pre: None. Assumes there may be excess characters in the input buffer.
// Post: Clears any residual characters from the input buffer, leaving it ready for the next input.

void length_to_metric(void);
// Pre: None. User has already selected to convert from feet/inches to meters/centimeters.
// Post: Prompts the user for feet and inches input, converts to meters and centimeters, 
//       and outputs the converted values.

void length_input_us(int *feet, double *inches);
// Pre: Pointers to an integer and a double are provided to store the input values.
// Post: Prompts the user for feet and inches values and stores them in the variables pointed to by feet and inches.

void length_convert_to_metric(int feet, double inches, int *meters, double *centimeters);
// Pre: Input values in feet and inches are provided. Pointers to an integer and a double are provided for the output.
// Post: Converts the given feet and inches to meters and centimeters, storing the results in the provided pointers.

void length_output_metric(int meters, double centimeters);
// Pre: Meters and centimeters values are provided.
// Post: Prints the converted length in meters and centimeters to the console.

void length_to_us(void);
// Pre: None. User has already selected to convert from meters/centimeters to feet/inches.
// Post: Prompts the user for meters and centimeters input, converts to feet and inches, 
//       and outputs the converted values.

void length_input_metric(double *meters, double *centimeters);
// Pre: Pointers to two doubles are provided to store the input values.
// Post: Prompts the user for meters and centimeters values and stores them in the variables pointed to by meters and centimeters.

void length_convert_to_us(double meters, double centimeters, int *feet, double *inches);
// Pre: Input values in meters and centimeters are provided. Pointers to an integer and a double are provided for the output.
// Post: Converts the given meters and centimeters to feet and inches, storing the results in the provided pointers.

void length_output_us(int feet, double inches);
// Pre: Feet and inches values are provided.
// Post: Prints the converted length in feet and inches to the console.

void weight_to_metric(void);
// Pre: None. User has already selected to convert from pounds/ounces to kilograms/grams.
// Post: Prompts the user for pounds and ounces input, converts to kilograms and grams, 
//       and outputs the converted values.

void weight_input_us(int *pounds, double *ounces);
// Pre: Pointers to an integer and a double are provided to store the input values.
// Post: Prompts the user for pounds and ounces values and stores them in the variables pointed to by pounds and ounces.

void weight_convert_to_metric(int pounds, double ounces, int *kilograms, double *grams);
// Pre: Input values in pounds and ounces are provided. Pointers to an integer and a double are provided for the output.
// Post: Converts the given pounds and ounces to kilograms and grams, storing the results in the provided pointers.

void weight_output_metric(int kilograms, double grams);
// Pre: Kilograms and grams values are provided.
// Post: Prints the converted weight in kilograms and grams to the console.

void weight_to_us(void);
// Pre: None. User has already selected to convert from kilograms/grams to pounds/ounces.
// Post: Prompts the user for kilograms and grams input, converts to pounds and ounces, 
//       and outputs the converted values.

void weight_input_metric(double *kilograms, double *grams);
// Pre: Pointers to two doubles are provided to store the input values.
// Post: Prompts the user for kilograms and grams values and stores them in the variables pointed to by kilograms and grams.

void weight_convert_to_us(double kilograms, double grams, int *pounds, double *ounces);
// Pre: Input values in kilograms and grams are provided. Pointers to an integer and a double are provided for the output.
// Post: Converts the given kilograms and grams to pounds and ounces, storing the results in the provided pointers.

void weight_output_us(int pounds, double ounces);
// Pre: Pounds and ounces values are provided.
// Post: Prints the converted weight in pounds and ounces to the console.

// Function definitions
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
        do
        {
            printf("Convert from feet/inches to meters/centimeters (1), meters/centimeters to feet/inches (2), or exit (0): ");
            scanf("%d", &choice);
            clear_buffer();
        } while (choice < 0 || choice > 2);

        if (choice == 1)
            length_to_metric();
        else if (choice == 2)
            length_to_us();
    } while (choice != 0);
}

void convert_weights(void)
{
    int choice;
    do
    {
        do
        {
            printf("Convert from pounds/ounces to kilograms/grams (1), kilograms/grams to pounds/ounces (2), or exit (0): ");
            scanf("%d", &choice);
            clear_buffer();
        } while (choice < 0 || choice > 2);

        if (choice == 1)
            weight_to_metric();
        else if (choice == 2)
            weight_to_us();
    } while (choice != 0);
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
    while (ans != '\n' && ans != EOF)
    {
        scanf("%c", &ans);
    }
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
    int valid_input = 0;
    while (!valid_input)
    {
        printf("Enter feet: ");
        if (scanf("%d", feet) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for feet.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    valid_input = 0;
    while (!valid_input)
    {
        printf("Enter inches: ");
        if (scanf("%lf", inches) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for inches.\n");
        }
        else
        {
            valid_input = 1;
        }
    }
}

void length_convert_to_metric(int feet, double inches, int *meters, double *centimeters)
{
    double total_inches = feet * FEET_TO_INCHES + inches;
    double total_meters = total_inches * METERS_IN_FOOT / INCHES_IN_FOOT;
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
    int valid_input = 0;
    while (!valid_input)
    {
        printf("Enter meters: ");
        if (scanf("%lf", meters) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for meters.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    valid_input = 0;
    while (!valid_input)
    {
        printf("Enter centimeters: ");
        if (scanf("%lf", centimeters) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for centimeters.\n");
        }
        else
        {
            valid_input = 1;
        }
    }
}

void length_convert_to_us(double meters, double centimeters, int *feet, double *inches)
{
    double total_feet = (meters + centimeters / 100) / METERS_IN_FOOT;
    *feet = (int)(total_feet);
    *inches = INCHES_IN_FOOT * (total_feet - *feet);
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
    int valid_input = 0;
    while (!valid_input)
    {
        printf("Enter pounds: ");
        if (scanf("%d", pounds) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for pounds.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    valid_input = 0;
    while (!valid_input)
    {
        printf("Enter ounces: ");
        if (scanf("%lf", ounces) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for ounces.\n");
        }
        else
        {
            valid_input = 1;
        }
    }
}

void weight_convert_to_metric(int pounds, double ounces, int *kilograms, double *grams)
{
    double total_pounds = pounds + ounces / OUNCES_IN_POUND;
    double total_kilograms = total_pounds / POUNDS_IN_KILOGRAMS;
    *kilograms = (int)total_kilograms;
    *grams = (total_kilograms - *kilograms) * GRAMS_IN_KILOGRAM;
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
    int valid_input = 0;
    while (!valid_input)
    {
        printf("Enter kilograms: ");
        if (scanf("%lf", kilograms) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for kilograms.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    valid_input = 0;
    while (!valid_input)
    {
        printf("Enter grams: ");
        if (scanf("%lf", grams) != 1)
        {
            clear_buffer();
            printf("Invalid input. Please enter a valid number for grams.\n");
        }
        else
        {
            valid_input = 1;
        }
    }
}

void weight_convert_to_us(double kilograms, double grams, int *pounds, double *ounces)
{
    double total_pounds = kilograms * POUNDS_IN_KILOGRAMS + grams / GRAMS_IN_KILOGRAM * POUNDS_IN_KILOGRAMS;
    *pounds = (int)total_pounds;
    *ounces = OUNCES_IN_POUND * (total_pounds - *pounds);
}

void weight_output_us(int pounds, double ounces)
{
    printf("Converted weight: %d pounds and %.2f ounces\n", pounds, ounces);
}
