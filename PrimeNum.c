#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int validate_int(char *input_msg, char *error_msg, int min, int max) {
    char buffer[100];
    char *endptr;
    int value;


    while (1) {
        printf("%s", input_msg);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error: System failed to read input. Exiting...\n");
                exit(EXIT_FAILURE);  }

        value = (int)strtol(buffer, &endptr, 10);

        if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) { printf("Error: %s\n\n", error_msg); continue; }

        // Only runs if min is not equal to max
        if (min != max) {
            if (value < min || value > max) { printf("Error: Input must be between %d and %d.\n\n", min, max); continue; }
        }

        break; 
    }
    return value;
}

int main() {

    int num = validate_int("Enter a Number: ","Invalid input. Please enter a Valid Whole Number.", 0,0);

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