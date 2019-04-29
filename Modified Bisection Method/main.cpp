#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#define delX 0.05
#define E 0.001

using namespace std;


float HornersRule(float arg, float coefs[], int len)
{
    float sum = coefs[0];
    for(int i = 1; i < len; i++)
    {
        sum = arg * sum + coefs[i];
    }

    return sum;
}

int main()
{

    cout << "Hello World!" << endl;

    float coefs[] = {1,-4,-10};
    int len = sizeof(coefs)/sizeof(float);

    float a;
    float b;
    float x1;
    float x2;
    float x0;
    float f1;
    float f2;
    float f0;
    float errorCheck;
    int count = 0;

    a = -2;
    b = 10;



    x1 = a;
    x2 = x1 + delX;


    while(x2 < b)
    {
        f1 = HornersRule(x1,coefs,len);
        f2 = HornersRule(x2,coefs,len);

        if(f1 * f2 < 0)

        {
            int iteration = 0;
            cout << "Iteration";
            cout << setw(10);
            cout << "x1";
            cout << setw(10);
            cout << "x2";
            cout << setw(10);
            cout << "x0";
            cout << setw(10);
            cout << "f1";
            cout << setw(10);
            cout << "f2";
            cout << setw(10);
            cout << "f0";
            cout << endl;


            while(true)
            {
                ++iteration;
                x0 = (x1 + x2)/2;
                f0 = HornersRule(x0,coefs,len);

                x0 = (x1 + x2)/2;
                f0 = HornersRule(x0,coefs,len);
                cout << setprecision(3) << fixed;
                cout << iteration;
                cout << setw(18);
                cout << x1;
                cout << setw(10);
                cout << x2;
                cout << setw(10);
                cout << x0;
                
                cout << setw(10);



                if(f1 < 0)
                {
                    cout << "-";
                    cout << setw(10);
                }
                else
                {
                    cout << "+";
                    cout << setw(10);
                }
                if(f2 < 0)
                {
                    cout << "-";
                    cout << setw(10);
                }
                else
                {
                    cout << "+";
                    cout << setw(10);
                }
                if(f0 < 0)
                {
                    cout << "-";
                    cout << endl;
                }
                else
                {
                    cout << "+";
                    cout << endl;
                }

                if(f1 * f0 < 0)
                {
                    x2 = x0;

                }

                else
                {
                    x1 = x0;
                    f1 = f0;
                }

                errorCheck = fabs((x2 - x1)/x2);
                if(errorCheck < E)
                {
                    count ++;
                    cout << endl << endl;
                    cout << "Root " << count <<  "  is : " <<  (x1 + x2)/2 << endl << endl;
                    break;
                }

            }

        }

        x1 = x2;
        x2 = x1 + delX;

    }

    cout << endl;

    return 0;

}
