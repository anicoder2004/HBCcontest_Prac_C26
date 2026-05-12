#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN and INT_MAX

int validate(char *input_msg, char *error_msg, int min, int max) {
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