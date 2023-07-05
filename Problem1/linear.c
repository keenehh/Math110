#include <stdio.h>

int extended_gcd(int a, int b, int *x, int *y) {
    // Initialize variables
    int x0 = 1;
    int y0 = 0;
    int x1 = 0;
    int y1 = 1;
    while (b != 0) {
        // quotient and remainder
        int quotient = a / b;
        int remainder = a % b;

        //coefficients
        int temp_x = x0 - quotient * x1;
        int temp_y = y0 - quotient * y1;
        x0 = x1;
        y0 = y1;
        x1 = temp_x;
        y1 = temp_y;
        // update
        a = b;
        b = remainder;
    }
    *x = x0;
    *y = y0;

    return a;
}


int lcm(int a, int b, int gcd) {        //function used to calculate the lcm
    return (a * b) / gcd;
}

void diophantine_solution(int a, int b, int c) {
    int x, y;
    int gcd = extended_gcd(a, b, &x, &y);
    if (c % gcd != 0) {     //when its not divisible its not solvable
        printf("No solution\n");
        return;
    }
    x = x * (c / gcd); //particular solution
    y = y * (c / gcd);
    /*
    printf("%d\n", x);
    printf("%d\n", y);
    lcm(a,b) = a*b/gcd(a,b)
    */
    printf("x = %d + %dn, y = %d - %dn\n", x, lcm(a,b,gcd)/a , y, lcm(a,b,gcd)/b);
}


int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    printf("ax + by = c\n");
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of c: ");
    scanf("%d", &c);

    printf("The general to %dx + %dy = %d is:\n", a, b, c);
    diophantine_solution(a, b, c);

    return 0;
}

