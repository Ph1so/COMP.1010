#include <stdio.h>

int main(int argc, char *argv[]){
    double h = 1.2;
    printf("%f\n", h);
    printf("%d\n", 42); // %d for integers
    printf("%c\n", 'A'); // single quotes for single characters (slow)
    printf("%c\n", 65); // ASCII
    printf("%c\n", 48); // memorize this one ASCII 48 = '0'
    printf("%.20lf\n", 1.0/3); // double floating point number
    printf("%.20f\n", 1.0/3); // floating point number
    return 0;
}