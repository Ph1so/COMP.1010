#include <stdio.h>

int main(int argc, char*argv[]){
    int sum = 0;
    for(int i = 1; i < 100000; i ++){
        if (((i*i)-2)%17 == 0)
            sum += 1;
    }
    printf("%d\n", sum);
}