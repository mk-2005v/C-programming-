/*
* Trigonometric Functions 
* implemented by using Taylor Series
* @see https://en.wikipedia.org/wiki/Taylor_series
*/


#include <stdio.h>
#include <math.h>

#define TRIG_MAX_ITER   21
#define TRIG_PI         3.14159265358979323846

double trig_sin(double x)
{
    double pow_x = 1.0;
    double fac = 1.0;
    double result = 0.0;
    double sign;
    for(size_t i = 0; i < TRIG_MAX_ITER - 1; i++)
    {
        if(i % 2 == 1)
        {
            sign = ((i - 1) / 2) % 2 == 0 ? 1.0 : -1.0;
            result += sign * pow_x / fac;
        }
        fac *= (double)(i + 1);
        pow_x = pow_x * x;
    }
    return result;
}

double trig_cos(double x)
{
    double pow_x = 1.0;
    double fac = 1.0;
    double result = 0.0;
    double sign;
    for(size_t i = 0; i < TRIG_MAX_ITER; i++)
    {
        if(i % 2 == 0)
        {
            sign = (i / 2) % 2 == 0 ? 1.0 : -1.0;
            result += sign * pow_x / fac;
        }
        fac *= (double)(i + 1);
        pow_x = pow_x * x;
    }
    return result;
}


double trig_tan(double x)
{
    double pow_x = 1.0;
    double fac = 1.0;
    double result_sin = 0.0;
    double result_cos = 0.0;
    double sign_sin;
    double sign_cos;
    for(size_t i = 0; i < TRIG_MAX_ITER; i++)
    {
        if(i % 2 == 1)
        {
            sign_sin = ((i - 1) / 2) % 2 == 0 ? 1.0 : -1.0;
            result_sin += sign_sin * pow_x / fac;
        }

        if(i % 2 == 0)
        {
            sign_cos = (i / 2) % 2 == 0 ? 1.0 : -1.0;
            result_cos += sign_cos * pow_x / fac;
        }
        fac *= (double)(i + 1);
        pow_x = pow_x * x;
    }
    return result_sin / result_cos;
}

double trig_arcsin(double x)
{
    double pow_x = 1.0;
    double pow4 = 1.0;
    double fac = 1.0;
    double fac2n = 1.0;
    double result = 0.0;
    for(size_t i = 0; i < TRIG_MAX_ITER + 1; i++)
    {
        if(i > 1)
        {
            fac2n *= (double)(i - 1);
        }
        if(i % 2 == 1)
        {
            if(i > 1)
            {
                fac *= ((double)(i - 1)) / 2.0;
            }
            fac = fac == 0 ? 1.0 : fac;
            result += (fac2n * pow_x) / (pow4 * (fac * fac) * ((double)i));
            pow4 *= 4;
        }
        pow_x = pow_x * x;
    }
    return result;
}

double trig_arccos(double x)
{
    return (TRIG_PI / 2.0) - trig_arcsin(x);
}

double trig_arctan(double x)
{
    double pow_x = 1.0;
    double result = 0.0;
    double sign;
    for(size_t i = 0; i < TRIG_MAX_ITER - 1; i++)
    {
        if(i % 2 == 1)
        {
            sign = ((i - 1) / 2) % 2 == 0 ? 1.0 : -1.0;

            result += sign * pow_x / ((double)i);
        }
        pow_x = pow_x * x;
    }
    return result;
}



double abs_diff(double a, double b)
{
    return a > b? a - b: b - a;
}

typedef double (*trig_f)(double);

#define test_param(x) &trig_ ## x, &x, #x
void test_func(double rad, trig_f f, trig_f sf, char *f_str)
{
    double trig_result = f(rad);
    double std_result = sf(rad);
    printf("trig_%s(%lf) = %lf, std_%s(%lf) = %lf, abs_error = %lf \n",
            f_str, rad, trig_result,
            f_str, rad, std_result,
            abs_diff(trig_result, std_result));
}


// TODO kaan: reverse trigonometric functions' test
// compare implementation and built in std trig. func. results
void test()
{
    // 0 < rad < pi/2
    double radians []= {0.33, 0.47, 0.44, 0.25, 0.12, 0.2};

    size_t sz = sizeof(radians) / sizeof(double);

    double rad;
    size_t i;
    for(i=0; i < sz; i++)
    {
        rad = radians[i] * TRIG_PI;
        test_func(rad, test_param(sin));
    }

    for(i=0; i < sz; i++)
    {
        rad = radians[i] * TRIG_PI;
        test_func(rad, test_param(cos));
    }

    for(i=0; i < sz; i++)
    {
        rad = radians[i] * TRIG_PI;
        test_func(rad, test_param(tan));
    }

}

int main()
{
    test();

    return 0;
}

