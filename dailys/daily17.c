/***********************************************
Author: Phi Nguyen
Date: 11/15/2024
Purpose: Practice reading and appending to files
Resources: NA
Time Spent: 8 minutess
***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp1, *fp2, *fp_out;
    int num1, num2;
    int noc1, noc2;

    fp1 = fopen("num1.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening num1.txt\n");
        exit(1);
    }

    fp2 = fopen("num2.txt", "r");
    if (fp2 == NULL) {
        printf("Error opening num2.txt\n");
        fclose(fp1);
        exit(1);
    }

    fp_out = fopen("final.txt", "w");
    if (fp_out == NULL) {
        printf("Error opening final.txt\n");
        fclose(fp1);
        fclose(fp2);
        exit(1);
    }

    noc1 = fscanf(fp1, "%d", &num1);
    noc2 = fscanf(fp2, "%d", &num2);

    while (1) {
        if (noc1 == EOF && noc2 == EOF) {
            break;
        }

        if (noc1 == EOF || (noc2 != EOF && num2 < num1)) {
            fprintf(fp_out, "%d\n", num2);
            noc2 = fscanf(fp2, "%d", &num2);
        } else {
            fprintf(fp_out, "%d\n", num1);
            noc1 = fscanf(fp1, "%d", &num1); 
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp_out);
    return 0;
}
