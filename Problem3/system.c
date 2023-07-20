#include <stdio.h>
#include <math.h>

//ngl the wiki for crt is so confusing

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int moduloThing(int m1, int m2) {  //somewhat redundant but whatever
    return m1 * m2;
}

int solve(int a1, int a2, int m1, int m2) {
    // check if m1 and m2 are coprime
    if (gcd(m1, m2) != 1) {
        printf("Error: m_1 and m_2 are not coprime.\n");
        return -1;
    }

    // apply crt
    int x = (a1 * m2 * modInverse(m2, m1) + a2 * m1 * modInverse(m1, m2)) % (m1 * m2);
    // A solution is given by x = a1m2n2+a2m1n1 - CRT WIKI
    // last % part is to only get the remainder
    //114 mod 63 to 51 mod 63.
    return x;
}

int main() {
    printf("x = a_1 mod m_1\n");
    printf("x = a_2 mod m_2\n");
    int a1 = 0;
    int m1 = 0;
    int a2 = 0;
    int m2 = 0;
    printf("Enter a_1: ");
    scanf("%d", &a1);

    printf("Enter m_1: ");
    scanf("%d", &m1);

    printf("Enter a_2: ");
    scanf("%d", &a2);
    
    printf("Enter m_2: ");
    scanf("%d", &m2);
    
    int result = solve(a1, a2, m1, m2);
    if (result != -1) { //not coprime
        printf("x ≡ %d (mod %d)\n", result, moduloThing(m1,m2));
    }

    return 0;
}
