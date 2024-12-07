#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 60

int read_names(FILE* fp, char* name1, char* name2);
int read_scores(FILE* fp, FILE* fpo, int* scores);

int main(void) {
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

    char first[MAX], last[MAX], name[120];
    int scores[10];

    // Process student data
    while (read_names(fp1, first, last)) {
        // Format the name
        int i = 0, j = 0;
        while (last[i] != '\0') {
            name[i] = last[i];
            i++;
        }
        name[i++] = ',';
        name[i++] = ' ';
        while (first[j] != '\0') {
            name[i++] = first[j++];
        }
        name[i] = '\0';

        // Output the formatted data
        fprintf(fp2, "%-20s", name); // Left-justified 20 characters for the name
        //fprintf(fp2, "\n");
        read_scores(fp1, fp2, scores);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int read_names(FILE* fp, char* name1, char* name2) {
    char t;
    int i = 0;

    // Read the first name
    while(isspace(t = fgetc(fp)));
    ungetc(t, fp);
    while (1) {
        t = fgetc(fp);
        if(t == EOF || t == '\n') return 0;
        if(t == ' ') break;
        name1[i++] = t;
        if (i >= MAX) {
            printf("Exceeded allocated memory. Name too long.\n");
            return 0;
        }
    }
    name1[i] = '\0';

    // Read the last name
    i = 0;
    while (1) {
        t = fgetc(fp);
        if(t == EOF) break;
        if(t == ' ' || t == '\n') break;
        name2[i++] = t;
        if (i >= MAX) {
            printf("Exceeded allocated memory. Name too long.\n");
            return 0;
        }
    }
    if(t == '\n') ungetc(t, fp);
    name2[i] = '\0';
    return 1;
}

int read_scores(FILE *fp, FILE *fpo, int *scores) {
    char c, buffer[4];
    int index = 0, score_count = 0, sum = 0;
    while (score_count < 10) {
        c = fgetc(fp);
        if (c == ' ' || c == '\n' || c == EOF) {
            if (index > 0) {
                buffer[index] = '\0';  // Null-terminate the current number
                scores[score_count] = atoi(buffer);  // Convert to integer and store
                sum += scores[score_count];  // Add to sum
                score_count++;  // Move to the next score
                index = 0;  // Reset buffer for the next number
            }
            if(c == '\n' || c == EOF) break;
        } 
        else if (isdigit(c)) {
            buffer[index++] = c;  // Add digit to buffer
            while((c = fgetc(fp)) != EOF && !isspace(c)){
                buffer[index++] = c;
            }
            ungetc(c, fp);
        } 
    }

    // Fill in remaining scores with 0 if fewer than 10 numbers are found
    for (int i = score_count; i < 10; i++) {
        scores[i] = 0;
    }

    // Output the scores
    for (int i = 0; i < 10; i++) {
        fprintf(fpo, "%4d", scores[i]);  // Right-justified 4 characters for each score
    }

    // Calculate and print the average
    double avg = (double)sum / 10;
    fprintf(fpo, "%10.2f\n", avg);  // Right-justified 10 characters for the average

    return 0;
}