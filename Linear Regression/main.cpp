#include <bits/stdc++.h>


using namespace std;


int main()
{
    freopen("input.txt","r",stdin);
    int n;
    float x;
    float y;
    float sumX = 0;
    float sumY = 0;
    float sumXX = 0;
    float sumXY = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        sumX = sumX + x;
        sumY = sumY + y;
        sumXX = sumXX + (x*x);
        sumXY = sumXY + (x*y);

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
    double a = (sumY/n) - (b*(sumX/n));

    cout << a << " ";
    if(b < 0)
    {
        cout << "-" << b << "x" << endl;
    }
    else
        cout << "+" << b << "x" << endl;


    return 0;


}
