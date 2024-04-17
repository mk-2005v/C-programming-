/**
 * @file
 * @brief Numerical Differentation
 * (https://en.wikipedia.org/wiki/Numerical_differentiation) is an algorithm
 * that is used to approximate the derivative of a mathematical function at a
 * given x value.
 * @details
 * This method uses a higher order of the standard numerical differentation
 * formula to approximate the second derivate of a function at x. The algorithm
 * follows the second derivative three-point midpoint formula represented by
 * f''(x) = (f(x + h) + 2f(x) + f(x-h)) / h^2 and has a remainder term of
 * -(h^2)/12 * f^4(zi)
 */

#include <assert.h>  // For assert
#include <math.h>    // For basic math functions
#include <stdio.h>   // For basic IO

/**
 * @brief A basic function, f(x) = 1 / (x + 1)
 * @param x Any double that does not equal -1
 * @return Returns 1 / (x + 1) of the given x
 */
double function_f(double x) { return 1 / (x + 1); }

/**
 * @brief The second order derivative of f(x) = 1 / (x + 1). This function is
 * solely used to find the absolute error in the test cases.
 * @param x Any x for which the second derivative of f(x) at x wants to be
 * found. X cannot be equal to -1.
 * @returns The second derivative of f(x) at x
 */
double function_f_double_prime(double x) { return 2 / pow((x + 1), 3); }

/**
 * @brief The fourth order derivative of f(x) = 1 / (x + 1). This function is
 * solely used to find the maximum of the remainder term in the test cases.
 * @param x Any x for which the fourth derivative of f(x) at x wants to be
 * found. X cannot be equal to -1.
 * @returns The fourth derivative of f(x) at x
 */
double function_f_fourth_prime(double x) { return 24 / pow((x + 1), 5); }

/**
 * @brief function g(x) = e^(2x) / x
 * @param x Any double that does not equal 0
 * @return Returns e^(2x) / x for the given x
 */
double function_g(double x) { return exp(2 * x) / x; }

/**
 * @brief The second derivative of g(x) = e^(4x) / x. This function is
 * solely used to calculate the absolute error in the test case
 * @param x Any x for which the second derivative of g(x) at x wants to be
 * found. X cannot be equal to 0.
 * @returns The second derivative of g(x) at x
 *
 */
double function_g_double_prime(double x)
{
    return (((4 * x * x) - (4 * x) + 2) * exp(2 * x)) / pow(x, 3);
}

/**
 * @brief The fourth order derivative of g(x) = e^(4x) / x. This function is
 * solely used to find the maximum of the remainder term in the test cases.
 * @param x Any x for which the fourth derivative of g(x) at x wants to be
 * found. X cannot be equal to 0.
 * @returns The fourth derivative of g(x) at x
 */
double function_g_fourth_prime(double x)
{
    return (((16 * pow(x, 4)) - (32 * pow(x, 3)) + (48 * x * x) - (48 * x) +
             24) *
            exp(2 * x)) /
           pow(x, 5);
}

/**
 * @brief Approximates the value of f"(x) through the second derivate midpoint
 * formula
 * @param x Any double defined on the function's interval
 * @param h Any double value that approaches zero, the closer the value is to
 * zero the more precise of an approximate. Warning: H cannot be zero
 * @param function A function pointer that points to the function being used to
 * find f"(x)
 * @return An approximation of the second derivative of the given function at
 * point x
 */
double differentation_second_derivative(double x, double h,
                                        double (*function)(double))
{
    return (function(x - h) - (2 * function(x)) + function(x + h)) / (h * h);
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
double second_derivative_calculate_max_error(
    double zi, double h, double (*f_quadruple_prime)(double))
{
    return (h * h * fabs(f_quadruple_prime(zi))) / 12;
}

/**
 * @brief A basic test implementation to verify the absolute error (true value -
 * approx value) is less than the maximum of the remainder term
 * @returns void
 */
static void test()
{
    // Validates that | true f''(x) - approx f''(x) | < | Max Remainder Term |
    assert(fabs(differentation_second_derivative(2, 0.01, function_f) -
                function_f_double_prime(2)) <
           second_derivative_calculate_max_error(2 - 0.01, 0.01,
                                                 function_f_fourth_prime));

    printf("f''(%d) ~ %.6f\n", 2,
           differentation_second_derivative(2, 0.01, function_f));
    printf("f''(%d) = %.6f\n", 2, function_f_double_prime(2));

    // Validates that | true g''(x) - approx g''(x) | < | Max Remainder Term |
    assert(fabs(differentation_second_derivative(1.6, 0.1, function_g) -
                function_g_double_prime(1.6)) <
           second_derivative_calculate_max_error(1.6 + 0.1, 0.1,
                                                 function_g_fourth_prime));

    printf("\ng''(%f) ~ %.6f\n", 1.6,
           differentation_second_derivative(1.6, 0.1, function_g));
    printf("g''(%f) = %.6f\n", 1.6, function_g_double_prime(1.6));

    printf("Successfully Passed All Tests!\n");
}

int main()
{
    test();
    return 0;
}
