
/// Linear Regression (Straight-line)
/// Book(example 10.1)

#include<bits/stdc++.h>

using namespace std;

int n = 5;
double X[] = { 1, 2, 3, 4, 5};
double Y[] = { 3, 4, 5, 6, 8};
double xSqr[100];
double xy[100];

int main(void)
{
    double sum_x = 0;
    double sum_y = 0;
    double sum_xSqr = 0;
    double sum_xy = 0;
    double a , b;

    cout << "\tx\t" << "y\t" << "x^2\t" << "xy\t" << endl;

    for(int i = 0;i < n;i++)
    {
        double xSqr = pow(X[i],2);
        double xy = X[i] * Y[i];

        sum_x = sum_x + X[i];
        sum_y = sum_y + Y[i];
        sum_xSqr = sum_xSqr + pow(X[i],2);
        sum_xy = sum_xy + (X[i] * Y[i]);
        cout << "\t" << X[i] << "\t" << Y[i] << "\t" << xSqr << "\t" << xy << "\t" << endl;
    }

    cout << endl << "Sum :\t" << sum_x << "\t" << sum_y << "\t" << sum_xSqr << "\t" << sum_xy << "\t" << endl;

    double denominator = ((n * sum_xSqr) - (pow(sum_x,2)));
    if(denominator == 0)
    {
        cout << "Cannot calculate equation!" << endl ;
        return 0;
    }
    b = ((n * sum_xy)-(sum_x * sum_y))/ denominator;

    a = (sum_y/n) - (b * (sum_x/n));

    cout << endl << "Equation: " << endl << endl ;
    cout << "Y = " << a << "+" << b << "x" << endl << endl ;


    return 0;
}
