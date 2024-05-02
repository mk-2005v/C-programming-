#include <stdio.h>
#include <float.h>

#define NR_DE               1.0e-8
#define NR_MAX_ITER         55


typedef double (*DFUNC2D) (double, double);
typedef double (*DFUNC1D) (double);

double abs_diff(double a, double b)
{
    return a > b? a - b: b - a;
}

/*
* Newton Raphson Method
* use to find point that intersect to x-axis
* for f(x) = y ==> (x0,0)
* f  : function (callback)  = cx^t + a
* df : derivative of f
* iteration: x1 = x0 - f(x0)/df(x0)
*/
double nr(double a, DFUNC2D f, DFUNC1D df)
{
    // initial point is chosen 1.0, can be any number
    static const double initial_point = 1.0; 
    int iter = 0;
    double old_x;
    double x = initial_point; 
    do{
        old_x = x;
        x = x - f(x,a) / df(x);
        iter++;
    }while(iter < NR_MAX_ITER && NR_DE < abs_diff(old_x, x) );
    return x;
}

// root of parabola is actually a sqrt of a
double parabola(double x, double a)
{
    return x*x - a;
}

double deriv_parabola(double x)
{
    return 2*x;
}

// sqrt of x
double square_root(double x)
{
    return nr(x, &parabola, &deriv_parabola);
}

void test_sqrt()
{
    double numbers[] = {12, 4, 16, 3, 9, 49};

    size_t sz = sizeof(numbers) / sizeof(double);

    double root;
    size_t i;
    for(i = 0; i < sz; i++)
    {
        root = square_root(numbers[i]);
        printf(" square_root(%lf) = %lf, square_abs_error = %lf \n", numbers[i], root, abs_diff(numbers[i], root * root));
    }

}

int main(){
    
    test_sqrt();

    return 0;
}
