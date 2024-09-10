#include <math.h>
#include "calculations.h"

float calculateArea(float sideA, float sideB, float sideC) {
    float p = (sideA + sideB + sideC) / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

float calculatePerimeter(float sideA, float sideB, float sideC) {
    return sideA + sideB + sideC;
}

float calculateHeight(float side, float area) {
    return (2 * area) / side;
}

float calculateMedian(float sideA, float sideB, float sideC) {
    return sqrt(2 * pow(sideB, 2) + 2 * pow(sideC, 2) - pow(sideA, 2)) / 2;
}

float calculateBisector(float sideA, float sideB, float sideC) {
    float p = (sideA + sideB + sideC) / 2;
    return 2 * sqrt(sideB * sideC * p * (p - sideA)) / (sideB + sideC);
}
