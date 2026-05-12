#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "validate_func.h"

int main() {

    int num = validate("Enter a Number: ","Invalid input. Please enter a Valid Whole Number.", 0,0);

    bool isPrime = true;

    if (num <= 1) { isPrime = false; } 
    else {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) { isPrime = false; break; } }
    }

    if (isPrime){ printf("%d is a prime number.\n", num); }
    else { printf("%d is not a prime number.\n", num); }

    return 0;
}