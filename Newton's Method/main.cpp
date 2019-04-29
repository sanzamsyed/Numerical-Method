#include <bits/stdc++.h>
#define E 0.001

using namespace std;

vector <float> coefs;
vector <float> coefs_p;
int order;


float HR(float arg, vector <float> v)
{
    int len = v.size();
    float sum = v[0];


    for(int i  = 1; i < len; i++)
    {
        sum = arg * sum + v[i];
    }

    return sum;
}



void Derivative()
{
    int len;
    len = coefs.size();

    coefs_p.clear();

    for(int i = 0; i < len - 1; i++)
    {
        coefs_p.push_back(coefs[i] * (order - i));
    }
}


void SD(float arg)
{
    float var = 0;
    vector <float> temp;
    int len = coefs.size();

    for(int i = 0; i < len; i++)
    {
        var = coefs[i] + var*arg;
        temp.push_back(var);
    }

    coefs.clear();
    coefs = temp;

    order--;

    Derivative();
}



void NewtonsMethod()
{
    float x0;
    float xr;

    float f;
    float fdash;

    float errorCheck;

    cin >> x0;

    while(order > 1)
    {
        
        
        do
        {
            f = HR(x0,coefs);
            fdash = HR(x0,coefs_p);

            xr = x0 - (f/fdash);

            errorCheck  = fabs((xr - x0)/xr);

            x0 = xr;
        }

        while(errorCheck > E);

        cout << "Root is : " << xr << endl;

        SD(xr);

    }

    cout << "Root is : " << (-1) * (coefs[1]/coefs[0]);
    cout << endl;


}



int main()
{

    cout << "Order : " << endl;
    cin >> order;
    float Arr[] = {1,-21,20,0};
    int lenAr = sizeof(Arr)/sizeof(float);

    for(int i = 0; i < lenAr; i++)
    {
        coefs.push_back(Arr[i]);
    }

    Derivative();

    NewtonsMethod();




}
