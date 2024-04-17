/**
 * @file
 * @brief Numerical Differentation
 * (https://en.wikipedia.org/wiki/Numerical_differentiation) is an algorithm
 * that is used to approximate the derivative of a mathematical function at a
 * given x value.
 * @details
 * This method consists of using the symmetric difference quotient to compute
 * the slope of the line that passes through the points (x - h, f(x - h)) and (x
 * + h, f(x + h)). The slope of the line becomes (f(x + h) - f(x - h)) / 2h, and
 * as h decreases, the approximation of f'(x) approaches the true value of
 * f'(x).
 * @author [Albert Adamson](https://github.com/Ajadamson206)
 */

#include <assert.h>  // For assert
#include <math.h>    // For basic math functions
#include <stdio.h>   // For basic IO

/**
 * @brief A basic function, f(x) = 1 / (x + 1)
 * @param x Any double that does not equal -1
 * @returns 1 / (x + 1) of the given x
 */
double function_f(double x) { return 1 / (x + 1); }

/**
 * @brief The derivative of f(x) = 1 / (x + 1). This function is solely used to
 * find the absolute error in the test cases.
 * @param x Any x for which the slope at f(x) wants to be found. Cannot be equal
 * to -1.
 * @returns The derivative of f(x) at x
 */
double function_f_prime(double x) { return (-1 / pow(x + 1, 2)); }

/**
 * @brief The 3rd order derivative of f(x) = 1 / (x + 1). This function is
 * solely used to find the maximum of the remainder term in the test cases.
 * @param x Any x for which the third derivative of f(x) at x wants to be found.
 * X cannot be equal to -1.
 * @returns The third derivative of f(x) at x
 */
double function_f_triple_prime(double x) { return (-6 / pow(x + 1, 4)); }

/**
 * @brief function g(x) = e^(4x) / x
 * @param x Any double that does not equal 0
 * @returns e^(4x) / x for the given x
 */
double function_g(double x) { return exp(4 * x) / x; }

/**
 * @brief The derivative of g(x) = e^(4x) / x. This function is solely used to
 * find the absolute error in the test cases.
 * @param x Any x for which the slope at g(x) wants to be found. Cannot be equal
 * to 0.
 * @returns The derivative of g(x) at x
 */
double function_g_prime(double x)
{
    return (((4 * x) - 1) * exp(4 * x)) / (x * x);
}

/**
 * @brief The 3rd order derivative of g(x) = e^(4x) / x. This function is
 * solely used to find the maximum of the remainder term in the test cases.
 * @param x Any x for which the third derivative of g(x) at x wants to be found.
 * X cannot be equal to 0.
 * @returns The third derivative of g(x) at x
 */
double function_g_triple_prime(double x)
{
    return (
        (((64 * pow(x, 3)) - (48 * pow(x, 2)) + (24 * x) - 6) * exp(4 * x)) /
        pow(x, 4));
}

/**
 * @brief Approximates the value of f'(x) through the three-point midpoint
 * formula
 * @param x Any double that is defined on the function's interval
 * @param h A double value that approaches zero, the closer it is to zero the
 * more precise the approximation is. Warning: H cannot be a zero
 * @param function A function pointer that points to the function which is going
 * to be used to find f'(x)
 * @returns The approximate derivate of the function at point x
 */
double differentation_three_midpoint(double x, double h,
                                     double (*function)(double))
{
    return ((function(x + h) - function(x - h)) / (2 * h));
}

/**
 * @brief Calculates the maximum error value of the approximation of f'(x) by
 * using the remainder term in the formula
 * @param zi The absolute maximum value of x on interval (x - h, x + h) for
 * f'''(x)
 * @param h The h value that was used to find f'(x)
 * @param f_triple_prime A function pointer to f'''(x) which is needed to find
 * the remainder term
 * @returns The maximum error of the approximation for f'(x)
 */
double calculate_max_error(double zi, double h,
                           double (*f_triple_prime)(double))
{
    return ((h * h) / 6) * fabs(f_triple_prime(zi));
}
/**
 * @brief A basic test implementation to verify the absolute error is less than
 * the maximum of the remainder term
 * @returns void
 */
static void test()
{
    // Validates that | true f'(x) - approx f'(x) | < (h^2 / 6) * | f'''(zi_x) |
    assert(fabs(differentation_three_midpoint(2, 0.01, function_f) -
                function_f_prime(2)) <
           calculate_max_error(2 - 0.01, 0.01, function_f_triple_prime));

    printf("f''(%d) ~ %.6f\n", 2,
           differentation_three_midpoint(2, 0.01, function_f));
    printf("f''(%d) = %.6f\n", 2, function_f_prime(2));

    // Validates that | true g'(x) - approx g'(x) | < (h^2 / 6) * | g'''(zi_x) |
    assert(fabs(differentation_three_midpoint(1.6, 0.1, function_g) -
                function_g_prime(1.6)) <
           calculate_max_error(1.6 + 0.1, 0.1, function_g_triple_prime));

    printf("\ng''(%f) ~ %.6f\n", 1.6,
           differentation_three_midpoint(1.6, 0.1, function_g));
    printf("g''(%f) = %.6f\n", 1.6, function_g_prime(1.6));

    printf("Successfully Passed All Tests!\n");
}

int main()
{
    test();
    return 0;
}
