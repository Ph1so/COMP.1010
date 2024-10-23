# include <stdio.h>

int main(int argc, char *argv[]){
    int t = 42;
    int* ptr = &t;
    int** ptr_ptr = &ptr;
    printf("%d\n", t);
    printf("%d\n", *ptr);
    printf("%d\n", **ptr_ptr);
    return 0;
}

//  * = deref?