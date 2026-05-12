#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "validate_func.h"

int get_validated_num() {
    char buffer[100];
    char *endptr;
    int mark;

    while (1) {
        printf("Enter a Number: ");
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error: System failed to read input. Exiting...\n");
            exit(EXIT_FAILURE); }

        mark = strtod(buffer, &endptr);

        if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
            printf("Error: Invalid input. Please enter a Valid Whole Number.\n\n");
            continue; }

        break; 
    }
    return mark;
}

int main() {

   // int num = get_validated_num();

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