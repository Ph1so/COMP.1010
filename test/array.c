#include <stdio.h>

void test(double array[]);

int main(int argc, char* argv[]){

    double nums[10] = {0,1,2,3,4,5,6,7,8,9};
    test(nums);
    double s = 1.2222;
    printf("%.2f", s);
}

void test(double array[]){
    printf("%d", sizeof(array));

}