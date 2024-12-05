#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int MAX = 100;
int read_names(FILE* fp, char* name1, char* name2);
int read_scores(FILE* fp, double* score);

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

    char first[MAX];
    char last[MAX];
    char name[120];
    double scores[10];
    double sum;
    double average;

    // Process student data
    while (read_names(fp1, first, last)) {
        sum = 0;

        if(read_scores(fp1, scores) == -1) {
            fclose(fp1);
            fclose(fp2);
            exit(1);
        }

        // Calculate the average
        for (int i = 0; i < 10; i++) {
            sum += scores[i];
        }
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

int read_names(FILE* fp, char* name1, char* name2){
    char t;
    int i = 0;
    while(isalpha(t = fgetc(fp))){
        name1[i] = t;
        i++;
        if(i > MAX){
            printf("Exceeded allocated memory. Name too long");
            return 0;
        }
    }
    if(i == 0)
        return 0;
    name1[i++] = '\0';
    i = 0;
    while(isalpha(t = fgetc(fp))){
        name2[i] = t;
        i++;
    }
    name2[i++] = '\0';
    return 1;
}

int read_scores(FILE* fp, double* scores){
    char c;
    char buffer[10];  
    int index = 0;
    int score_count = 0;

    while (score_count < 10) {
        index = 0;

        while ((c = fgetc(fp)) != EOF && !isdigit(c));
        
        if (c == EOF) return -1;  
        

        do {
            buffer[index++] = c;
            c = fgetc(fp);
        } while (isdigit(c) || c == '.');
        
        buffer[index] = '\0'; 
        
     
        scores[score_count] = atof(buffer);
        
        if (scores[score_count] < 0) {
            printf("Invalid score encountered.\n");
            return -1; 
        }

        score_count++;
    }

    return 0; 
}
