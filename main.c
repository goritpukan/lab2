#include <stdio.h>
#include "./include/calculations.h"
#include "./include/validation.h"

int main(void) {
    double sideA = 0, sideB = 0, sideC = 0;

    double perimeter = 0, area = 0;
    double sideAHeight = 0, sideBHeight = 0, sideCHeight = 0;
    double sideAMedian = 0, sideBMedian = 0, sideCMedian = 0;
    double sideABisector = 0, sideBBisector = 0, sideCBisector = 0;

    unsigned char decimalPlaces = 0;

    printf("This is a program that calculates area, perimeter, heights, bisectors and medians of a triangle by the entered sides\n");
    printf("Program can calculate triangles with sides between 0.001 and 1000\n");


    while (1) {
        printf("\nEnter side of triangle A: ");
        if (scanf("%lf", &sideA) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideA < 0.001 || sideA > 1000) {
            handleInputErrorWithValue(0.001, 1000);
            continue;
        }

        printf("\nEnter side of triangle B: ");
        if (scanf("%lf", &sideB) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideB < 0.001 || sideB > 1000) {
            handleInputErrorWithValue(0.001, 1000);
            continue;
        }

        printf("\nEnter side of triangle C: ");
        if (scanf("%lf", &sideC) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (sideC < 0.001 || sideC > 1000) {
            handleInputErrorWithValue(0.001, 1000);
            continue;
        }

        if (validate(sideA, sideB, sideC) == 1) {
            continue;
        }
        printf("\nEnter number of decimal places(1 - 12): ");
        if (scanf("%hhu", &decimalPlaces) != 1) {
            handleInputErrorWithType();
            continue;
        }
        if (decimalPlaces == 0 || decimalPlaces > 12) {
            handleInputErrorWithValue(1, 12);
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


        printf("Perimeter: %.*lf\n", decimalPlaces, perimeter);
        printf("Area: %.*lf\n", decimalPlaces, area);

        printf("Height(a): %.*lf\n", decimalPlaces, sideAHeight);
        printf("Height(b): %.*lf\n", decimalPlaces, sideBHeight);
        printf("Height(c): %.*lf\n", decimalPlaces, sideCHeight);

        printf("Median(a): %.*lf\n", decimalPlaces, sideAMedian);
        printf("Median(b): %.*lf\n", decimalPlaces, sideBMedian);
        printf("Median(c): %.*lf\n", decimalPlaces, sideCMedian);

        printf("Bisector(a): %.*lf\n", decimalPlaces, sideABisector);
        printf("Bisector(b): %.*lf\n", decimalPlaces, sideBBisector);
        printf("Bisector(c): %.*lf\n", decimalPlaces, sideCBisector);

        printf("To enter new value press \"Enter\"\n");
        printf("To stop program enter any value, and press \"Enter\"\n");

        while (getchar() != '\n');
        if (getchar() == 10) {
            continue;
        } else {
            break;
        }
    }

    return 0;
}
