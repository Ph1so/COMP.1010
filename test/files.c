#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE * fp;
    fp = fopen("test.txt", "r");
    int biggest = 0;
    char cur;
    while((cur = fgetc(fp)) != EOF){
        if(isdigit(cur)){
            if(atoi(cur) > biggest)
                biggest = cur;
        }
    }
    printf("%d", biggest);
    fclose(fp);
    return 0;
}