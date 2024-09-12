#include <math.h>
#include "../include/calculations.h"

double calculateArea(double sideA, double sideB, double sideC) {
    double p = (sideA + sideB + sideC) / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double calculatePerimeter(double sideA, double sideB, double sideC) {
    return sideA + sideB + sideC;
}

double calculateHeight(double side, double area) {
    return (2 * area) / side;
}

double calculateMedian(double sideA, double sideB, double sideC) {
    return sqrt(2 * pow(sideB, 2) + 2 * pow(sideC, 2) - pow(sideA, 2)) / 2;
}

double calculateBisector(double sideA, double sideB, double sideC) {
    double p = (sideA + sideB + sideC) / 2;
    return 2 * sqrt(sideB * sideC * p * (p - sideA)) / (sideB + sideC);
}
