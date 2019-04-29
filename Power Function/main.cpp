#include <bits/stdc++.h>


using namespace std;


int main()
{
    freopen("input2.txt","r",stdin);
    int n;
    float x;
    float y;
    float sumX = 0;
    float sumY = 0;
    float sumXX = 0;
    float sumXY = 0;
    cin >> n;

    cout << "xi" << "\t";
    cout << "yi" << "\t";
    cout << "lnxi" << "\t";
    cout << "lnyi" << "\t";
    cout << "(lnxi)^2" << "\t";
    cout << "(linx1)(lnyi)" <<endl;

    cout << setprecision(2) << fixed;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        cout << x << "\t";
        cout << y << "\t";
        cout << log(x) << "\t";
        cout << log(y) << "\t";
        cout << pow(log(x),2) << "               ";
        cout << (log(x) * log(y)) << "\n";

        sumX = (sumX +  x);
        sumY = (sumY + y);
        sumXX = (sumXX + log(x*x));
        sumXY = (sumXY + log(x*y));

    }




    double u1 = n * (sumXY);
    double u2 = sumX * sumY;
    double b1 = n * sumXX;
    double b2 = (sumX * sumX);

    if(b1 - b2 == 0)
    {
        cout << "No solution found!" << endl;
        return 0;
    }

    double b = (u1 - u2)/(b1 - b2);
    double R = (sumY/n) - (b*(sumX/n));
    double a = exp(R);

    cout << "a" << a << endl;
    cout << "b" << b << endl;


    return 0;


}
