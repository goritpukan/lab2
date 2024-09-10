#include <stdio.h>
#include "calculations.h"

void handleInputErrorWithType();

void handleInputErrorWithValue();

int validate(float sideA, float sideB, float sideC);


int main(void) {
    float sideA = 0, sideB = 0, sideC = 0;

    float perimeter = 0, area = 0;
    float sideAHeight = 0, sideBHeight = 0, sideCHeight = 0;
    float sideAMedian = 0, sideBMedian = 0, sideCMedian = 0;
    float sideABisector = 0, sideBBisector = 0, sideCBisector = 0;

    printf("This is a program that calculates area, perimeter, heights, bisectors and medians of a triangle by the entered sides\n");
    printf("Program can calculate triangles with sides between 0.001 and 1000\n");


    while (1) {
        printf("\nEnter side of triangle A: ");
        if (scanf("%f", &sideA) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideA < 0.001 || sideA > 1000) {
            handleInputErrorWithValue();
            continue;
        }

        printf("\nEnter side of triangle B: ");
        if (scanf("%f", &sideB) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideB < 0.001 || sideB > 1000) {
            handleInputErrorWithValue();
            continue;
        }

        printf("\nEnter side of triangle C: ");
        if (scanf("%f", &sideC) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideC < 0.001 || sideC > 1000) {
            handleInputErrorWithValue();
            continue;
        }
        if (validate(sideA, sideB, sideC) == 1) {
            continue;
        }
        area = calculateArea(sideA, sideB, sideC);
        perimeter = calculatePerimeter(sideA, sideB, sideC);

        sideAHeight = calculateHeight(sideA, area);
        sideBHeight = calculateHeight(sideB, area);
        sideCHeight = calculateHeight(sideC, area);

        sideAMedian = calculateMedian(sideA, sideB, sideC);
        sideBMedian = calculateMedian(sideB, sideC, sideA);
        sideCMedian = calculateMedian(sideC, sideA, sideB);

        sideABisector = calculateBisector(sideA, sideB, sideC);
        sideBBisector = calculateBisector(sideB, sideC, sideA);
        sideCBisector = calculateBisector(sideC, sideA, sideB);


        printf("Perimeter: %f\n", perimeter);
        printf("Area: %f\n", area);

        printf("Height(a): %f\n", sideAHeight);
        printf("Height(b): %f\n", sideBHeight);
        printf("Height(c): %f\n", sideCHeight);

        printf("Median(a): %f\n", sideAMedian);
        printf("Median(b): %f\n", sideBMedian);
        printf("Median(c): %f\n", sideCMedian);

        printf("Bisector(a): %f\n", sideABisector);
        printf("Bisector(b): %f\n", sideBBisector);
        printf("Bisector(c): %f\n", sideCBisector);

        printf("To enter new value press \"Enter\"\n");
        printf("To stop program enter any value, and press \"Enter\"\n");

        getchar();
        if (getchar() == 10) {
            continue;
        } else {
            break;
        }
    }


    return 0;
}

void handleInputErrorWithType() {
    printf("\nInput must be float or int!");
    printf("\nPlease, try again!");
    while (getchar() != '\n'); //Clear input buffer
}

void handleInputErrorWithValue() {
    printf("\nSide value must be between 0.001 and 1000.");
    printf("\nPlease, try again!");
    while (getchar() != '\n'); //Clear input buffer
}

int validate(float sideA, float sideB, float sideC) {
    if (!(sideA + sideB > sideC) || !(sideA + sideC > sideB) || !(sideB + sideC > sideA)) {
        printf("\n Sum of two sides of a triangle must be greater then the length of third side");
        return 1;
    }
    return 0;
}
