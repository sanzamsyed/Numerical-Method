#include <stdio.h>
#include <iostream>
#include <math.h>
#define E 0.001


/// x^2 - 4x - 10
/// 2*x - 4

using namespace std;


float HR(float arg, int Arr[],int length)
{

    float sum = Arr[0];

    for(int i = 1; i < length; i++)
    {
        sum = arg * sum + Arr[i];
    }

    return sum;
}

int main()
{
    int coefs1[] = {1,-4,-10};
    int len1 = sizeof(coefs1)/sizeof(int);
    int coefs2[] = {2,-4};
    int len2 = sizeof(coefs2)/sizeof(int);
    float x0;
    float x1;
    float f1;
    float f2;
    float errorCheck = 0;



    cin >> x0;


    do
    {
        //cout << "HAIL HYDRA!" << endl;
        f1 = HR(x0,coefs1,len1);
        f2 = HR(x0,coefs2,len2);
        x1 = x0 - (f1/f2);
        errorCheck = fabs((x1-x0)/x1);
        x0 = x1;

    }

    while(errorCheck > E);

    cout << "Root is : " << x0 << endl;


}
