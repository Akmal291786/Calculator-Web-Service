#include "Calculator.h"
#include <cmath>
#include <stdexcept>

// Addition
double Calculator::add(double a, double b) {
    return a + b;
}

// Subtraction
double Calculator::subtract(double a, double b) {
    return a - b;
}

// Multiplication
double Calculator::multiply(double a, double b) {
    return a * b;
}

// Division
double Calculator::divide(double a, double b) {

    if (b == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }

    return a / b;
}

// Modulus
int Calculator::modulus(int a, int b) {

    if (b == 0) {
        throw std::runtime_error("Modulus by zero is not allowed");
    }

    return a % b;
}

// Power
double Calculator::power(double a, double b) {
    return pow(a, b);
}

// Square root
double Calculator::squareRoot(double a) {

    if (a < 0) {
        throw std::runtime_error(
            "Square root of a negative number is not allowed"
        );
    }

    return sqrt(a);
}

// Percentage
double Calculator::percentage(double value, double percent) {
    return (value * percent) / 100.0;
}