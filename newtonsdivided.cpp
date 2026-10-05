#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, i, j;
    double x[10], y[10][10], value, result, term;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x values:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter y values:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> y[i][0];
    }

    
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1])
                      / (x[i + j] - x[i]);
        }
    }

    cout << "Enter the value of x to find f(x): ";
    cin >> value;

    
    result = y[0][0];

    for (j = 1; j < n; j++)
    {
        term = y[0][j];

        for (i = 0; i < j; i++)
        {
            term = term * (value - x[i]);
        }

        result = result + term;
    }

    cout << fixed << setprecision(4);
    cout << "\nf(" << setprecision(2) << value << ") = "
         << setprecision(4) << result << endl;

    return 0;
}
