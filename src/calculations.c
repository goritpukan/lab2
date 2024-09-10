#include <math.h>
#include "../include/calculations.h"

double calculateArea(double sideA, double sideB, double sideC) {
    double p = (sideA + sideB + sideC) / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double calculatePerimeter(float sideA, float sideB, float sideC) {
    return sideA + sideB + sideC;
}

double calculateHeight(float side, float area) {
    return (2 * area) / side;
}

double calculateMedian(float sideA, float sideB, float sideC) {
    return sqrt(2 * pow(sideB, 2) + 2 * pow(sideC, 2) - pow(sideA, 2)) / 2;
}

double calculateBisector(float sideA, float sideB, float sideC) {
    float p = (sideA + sideB + sideC) / 2;
    return 2 * sqrt(sideB * sideC * p * (p - sideA)) / (sideB + sideC);
}
