#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double f(double x)
{
    return x*x*x*x - 2*x*x - x + 2;
}


void modifiedBisection(double a, double b, int n)
{
    double xr, fa, fb, fxr;

    cout << "\nInterval: [" << a << ", " << b << "]\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Iter\t a\t\t b\t\t xr\t\t f(xr)\n";
    cout << "-------------------------------------------------------------\n";

    for(int i = 1; i <= n; i++)
    {
        fa = f(a);
        fb = f(b);


        xr = (a * fabs(fb) + b * fabs(fa))
             / (fabs(fa) + fabs(fb));

        fxr = f(xr);

        cout << i << "\t"
             << fixed << setprecision(6)
             << a << "\t"
             << b << "\t"
             << xr << "\t"
             << fxr << endl;


        if(fabs(fxr) < 0.000001)
            break;


        if(fa * fxr < 0)
        {
            b = xr;
        }
        else
        {
            a = xr;
        }
    }

    cout << "\nApproximate Root = "
         << fixed << setprecision(6) << xr << endl;
}

int main()
{
    modifiedBisection(-2, 0, 15);

    modifiedBisection(0, 1.5, 15);

    modifiedBisection(1.5, 3, 15);

    return 0;
}
