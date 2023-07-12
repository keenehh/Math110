#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool prime(int num) {
    //base cases for 1 and 2.
    if (num < 2) {      //when the number is 1
        return false;
    }
    if (num == 2) {     //when the number is 2
        return true;
    }
    if (num % 2 == 0) { //when the number is even
        return false;
    }

    for (int i = 3; i <= sqrt(num); i += 2) { //increment by 2 to skip even numbers. i guess that could be counted as more efficient since we already check % 2 above. incrementing by +1 would be a little slower
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    int pcount = 0;
    printf("Enter a number n: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d are: \n", n);
    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
            printf("%d ", i);
            pcount++;
        }
    }
    printf("\n");
    printf("There are %d prime numbers\n",pcount);
    return 0;
}
