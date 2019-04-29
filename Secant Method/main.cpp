#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define E 0.001
#define f(x) (x*x) - 4*x -10

using namespace std;

int main()
{
    float x1;
    float x2;
    float x3;
    float f1;
    float f2;
    float errorCheck;
    float root;
    int noOfIteration = 1;
    
    cout << "x1 : ";
    cin >> x1;
    cout << "x2 : ";
    cin >> x2;
    
    cout << "No.Of.Iteration  ";
    cout <<"\t\t";
    cout <<"Values of X";
    cout << endl;
    
    
    f1 = f(x1);
    f2 = f(x2);
    
 
    
    while(true)
    {
        cout << noOfIteration++;
        cout << "\t\t\t\t\t\t\t";
        x3 = ((f2*x1) - (f1*x2))/(f2 - f1);
        cout << "x 3 : " << x3 << endl;
        errorCheck = fabs((x3-x2)/x3);
        
        if(errorCheck > E)
        {
            x1 = x2;
            f1 = f2;
            x2 = x3;
            f2 = f(x3);
        }
        else
        {
            root = x3;
            break;
        }
    }
    
    cout << "Root is : " << root << endl;
    
    
}
