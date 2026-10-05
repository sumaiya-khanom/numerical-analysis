
#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x*x - 4*x + 2;
}

int main()
{
    double x0, x1, x2, error, tolerance;
    int n;

    cout << "Enter x0: ";
    cin >> x0;

    cout << "Enter x1: ";
    cin >> x1;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    cout << "\nIteration\t x0\t\t x1\t\t x2\t\t Error\n";

    for(n = 1; n <= 100; n++)
    {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        error = fabs(x2 - x1);

        cout << n << "\t\t"
             << x0 << "\t"
             << x1 << "\t"
             << x2 << "\t"
             << error << endl;

        if(error < tolerance)
            break;

        x0 = x1;
        x1 = x2;
    }

    cout << "\nApproximate root = " << x2 << endl;
    cout << "Number of iterations = " << n << endl;

    return 0;
}
