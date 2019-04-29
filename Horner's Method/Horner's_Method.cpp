#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

int Coefs[10];
int indexCount = 0;
int order;

float HR(int argument)
{
    float sum = Coefs[0];
    for(int i = 1; i <= indexCount; i++)
    {
        sum = argument * sum + Coefs[i];
    }

    return sum;


}

void Display()
{
    int count = 0;
    for(int i = order; i >= 0; i--)
    {
        if(i == 0)
        {

            cout << Coefs[count++] << " ";
        }
        else if(i == 1)
        {
            cout << Coefs[count++] << "x"<< " ";
        }
        else
        {
            cout << Coefs[count++] << "x^" << i << " ";
        }

    }
    cout  << endl;
}

int main()
{

    cout << "Order : ";
    cin >> order;
    for(int i = order; i > 0; i--)
    {
        int input;
        if(i!=1)
        {
            cout << "Coefficient of x^" << i <<" : ";
        }
        else
        {
            cout << "Coefficent of x : ";
        }
        cin >> input;
        Coefs[indexCount] = input;
        indexCount++;
    }


    cout << "Value of Constant : ";

    int input;
    cin >> input;
    Coefs[indexCount] = input;



    cout << endl << endl;

    cout << "The function is f(x) =  ";
    Display();
    cout << endl;
    cout << "Result: " << HR(3) << endl;


}

