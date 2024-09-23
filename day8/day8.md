# Fri Sep 20th

This example passes a copy of `x` to the function scanf

```c
int x = 4;
scanf("%d", x);
```

This example passes the address of `x` to the function scanf

```c
int x = 4;
scanf("%d", &x);
```

& is a uniary operator - only has one operand - evaluates as the address of some location

2+3 has two operands
