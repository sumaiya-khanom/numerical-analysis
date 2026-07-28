#include <iostream>
#include <cmath>
using namespace std;


double fun(double x)
{
    return x*x - 4*x + 2;
}


double dfun(double x)
{
    return 2*x - 4;
}

void newton(double x, double e)
{
    double x1;
    int itr = 1;

    while (true)
    {
        x1 = x - fun(x) / dfun(x);

        cout << itr << ". x = " << x
             << "   f(x) = " << fun(x)
             << "   f'(x) = " << dfun(x)
             << "   Next x = " << x1 << endl;

        if (fabs(x1 - x) < e)
            break;

        x = x1;
        itr++;
    }

    cout << "\nRoot = " << x1 << endl;
}

int main()
{
    double x;
    cout << "Enter Initial Guess: ";
    cin >> x;
    newton(x, 0.001);

    return 0;
}
