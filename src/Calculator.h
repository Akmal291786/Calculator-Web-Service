#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:

    // Basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // Additional mathematical operations
    int modulus(int a, int b);
    double power(double a, double b);
    double squareRoot(double a);
    double percentage(double value, double percent);
};

#endif