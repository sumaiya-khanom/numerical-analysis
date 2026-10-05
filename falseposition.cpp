
#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x*x - 4*x + 2;
}

int main()
{
    double a, b, c, oldc = 0, error, tolerance;
    int n;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    if (f(a) * f(b) >= 0)
    {
        cout << "Invalid interval!" << endl;
        return 0;
    }

    cout << "\nIteration   a   b   c   f(c)   Error\n";

    for (n = 1; n <= 100; n++)
    {
        c = a - (f(a) * (b - a)) / (f(b) - f(a));

        if (n == 1)
            error = 0;
        else
            error = fabs(c - oldc);

        cout << n << "   "
             << a << "   "
             << b << "   "
             << c << "   "
             << f(c) << "   "
             << error << endl;

        if (fabs(f(c)) < tolerance || (n > 1 && error < tolerance))
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        oldc = c;
    }

    cout << "\nApproximate root = " << c << endl;

    return 0;
}
