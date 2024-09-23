# Mon Sep 23rd

```c

#include <stdio.h>

int main(int argc, char *argv[])
{
    double x = 0.1;
    printf("%.20f\n", x); //%f is fixed notation - %e is exponential notation
    return 0;
}

```

This prints 0.10000000000000000555

post vs pre increments

```c
int count = 1;

+++count;
count+++;
```
