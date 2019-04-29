#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#define f(x) (x*x) - 4*x - 10
#define e 0.001

using namespace std;

int main()
{
    float x1;
    float x2;
    float x0;
    float f1;
    float f2;
    float f0;

    int cnt = 0;

    float temp;
    float absoluteValue;



    doAgain:

        cout <<  "FINDING  ROOT " << cnt + 1 << endl << endl;


    do
    {

        cout << "x1 : ";
        cin >> x1;
        cout << "x2 : ";
        cin >> x2;

        f1 = f(x1);
        f2 = f(x2);
    }

    while(f1 * f2 > 0);

    int iteration = 0;

    cout << endl << endl;

    cout <<"Iteration";
    cout << "\t";
    cout << "x1";
   cout << "\t";
    cout << "x2";
    cout << "\t";
    cout << "x0";
    cout << "\t";
    cout << "f1";
    cout << "\t";
    cout << "f2";
    cout << "\t";
    cout << "f0";
    cout << endl;

    do
    {
        iteration++;

        temp = (x2 - x1)/x2;
        absoluteValue = fabs(temp);
        x0 = (x1 + x2)/2;
        f0 = f(x0);

        if(f0 == 0)
        {
            cout << "Root is : " << x0 << endl;
            break;
        }
        else if(f1 * f0 < 0)
        {
            x2 = x0;
        }

        else
        {
            x1 = x0;
        }

        cout << setprecision(3) << fixed;
        cout <<iteration;
        cout << "\t\t";
        cout << x1;
        cout << "\t";
        cout << x2;
        cout << "\t";
        cout << x0;
        cout << "\t";

        if(f1 < 0)
        {
            cout << "-" << "\t";
        }
        else
        {
            cout << "+" << "\t";
        }
        if(f2 < 0)
        {
            cout << "-" << "\t";
        }
        else
        {
            cout << "+" << "\t";
        }
        if(f0 < 0)
        {
            cout << "-" << endl;
        }
        else
        {
            cout << "+" << endl;
        }




    }

    while(absoluteValue > e);

    cnt++;
    cout << endl <<  "Root " << cnt << " is " << x0 << endl << endl << endl;

    if(cnt < 2)
    {
        goto doAgain;
    }

}
