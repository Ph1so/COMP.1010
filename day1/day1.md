# Fri Sep 6th

never auto run latest succesful build
always debug from top to bottom

be able to write main.c from memory - define main() with command line params

```c
int main(int argc, char *argv[]) //int = "return type" // "main" is the function
{
    return 0; // number 0 = false
}
```

"main" is the entry point - program will look for "main" - if there is no "main" program wont "link"

formal parameters:

This is a "header"

```c

int main(int argc, char *argv[])

```

This is the "body"

```c

{
    return 0; // returning 0 means "main" ran without errors // status
}

```
