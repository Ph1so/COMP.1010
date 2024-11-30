#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp1, *fp2;

    // Open input file
    fp1 = fopen("quiz.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening quiz.txt\n");
        exit(1);
    }

    // Open output file
    fp2 = fopen("average.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening average.txt\n");
        fclose(fp1);
        exit(1);
    }

    char first[100];
    char last[100];
    char name[120];
    double scores[10];
    int sum;
    double average;

    // Process student data
    while (fscanf(fp1, "%s %s", first, last) == 2) {
        sum = 0;

        // Read the 10 quiz scores
        for (int i = 0; i < 10; i++) {
            if (fscanf(fp1, "%lf", &scores[i]) != 1) {
                printf("Error reading quiz score for %s %s\n", first, last);
                fclose(fp1);
                fclose(fp2);
                exit(1);
            }
            sum += scores[i];
        }

        // Calculate the average
        average = sum / 10.0;

        // Format the name
        int i = 0;
        while (last[i] != '\0') {
            name[i] = last[i];
            i++;
        }

        name[i++] = ',';  
        name[i++] = ' ';  

        int j = 0;
        while (first[j] != '\0') {
            name[i + j] = first[j];
            j++;
        }
        name[i + j] = '\0';

        // Output the formatted data
        fprintf(fp2, "%-20s", name); // Left-justified 20 characters for the name
        for (int i = 0; i < 10; i++) {
            fprintf(fp2, "%4.0f", scores[i]); // Right-justified 4 characters for each score
        }
        fprintf(fp2, "%10.2f\n", average); // Right-justified 10 characters for the average
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
