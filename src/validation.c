#include <stdio.h>
#include "../include/validation.h"

void handleInputErrorWithType() {
    printf("\nInvalid input type!");
    printf("\nPlease, try again!");
    while (getchar() != '\n');
}

void handleInputErrorWithValue(float min, int max) {
    printf("\nSide value must be between %.3f and %d", min, max);
    printf("\nPlease, try again!");
    while (getchar() != '\n');
}

int validate(float sideA, float sideB, float sideC) {
    if (!(sideA + sideB > sideC) || !(sideA + sideC > sideB) || !(sideB + sideC > sideA)) {
        printf("\n Sum of two sides of a triangle must be greater then the length of third side");
        return 1;
    }
    return 0;
}