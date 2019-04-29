#include <stdio.h>
#include <iostream>
#include <math.h>
#define E 0.001

using namespace std;

float HR(float arg, int Arr[], int len)
{
    float sum = Arr[0];
    for(int i = 1; i < len; i++)
    {
        sum = arg * sum + Arr[i];
    }

    return sum;
}


int main()
{
    int coefs[] = {1,-4,-10};
    int length = sizeof(coefs)/sizeof(int);
    float x1;
    float x2;
    float x3;
    float f1;
    float f2;
    float f3;
    float errorCheck = 0;
    cin >> x1 >> x2;

    f1 = HR(x1, coefs, length);
    f2 = HR(x2, coefs, length);

    while(true)
    {
        cout << "HAIL HYDRA!" << endl;

        x3 = ((f2*x1) - (f1 * x2))/(f2 - f1);

        errorCheck = fabs((x3 - x2)/x3);

        if(errorCheck > E)
        {
            x1 = x2;
            f1 = f2;
            x2 = x3;
            f2 = HR(x3,coefs,length);
        }

        else
        {
            cout << "Root is : " << x3 << endl;
            break;
        }

    }

}
