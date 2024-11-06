#include <stdio.h>

int main(int argc, char* argv[]){
    int i;
    printf("%d\n", argc);
    for(i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    int* p;
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    p = nums;
    printf("nums = %p\n", nums);
    printf("p = %p\n", p);
    printf("p[0] = %d\n", p[0]);
    int hello = 22;
    p = &hello;
    printf("p[0] = %d\n", p[0]);

}