#include <bits/stdc++.h>

using namespace std;


int main()
{


    //freopen("input.txt","r",stdin);

    int order = 3;
    float Matrix[order][order + 1];
    float Res[order];

    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order + 1; j++)
        {
            float input;
            cin >> input;
            Matrix[i][j] =input;

        }
    }



    ///---------->FORWARD CALCULATION STEP 1 <--------------------///

    int j = 1;

    while(j < 3)
    {



        float div = Matrix[j][0]/Matrix[0][0];

        for(int i = 0; i < 4; i++)
        {
            float temp = 0;
            temp = Matrix[0][i] * div;
            Matrix[j][i] = Matrix[j][i] - temp;
        }


        j++;


    }

    ///FORWARD CALCULATION STEP 1 ENDS HERE///




    ///FORWARD CALCUlATION STEP 2 STARTS HERE///


    float div2 = Matrix[2][1]/Matrix[1][1];

    for(int i = 1; i < order + 1; i++)
    {
        float temp = 0;
        temp = Matrix[1][i] * div2;
        Matrix[2][i] = Matrix[2][i] - temp;
    }



    for(int i = 0; i < order; i++)
    {
        for(int j = 0;  j < order + 1; j++)
        {
            cout <<setprecision(2) << fixed << Matrix[i][j] << "\t\t";
        }

        cout << endl;
    }

    ///FORWARD CALCULATION STEP 2 ENDS HERE///



    ///BACKCALCULATION STARTS HERE///

    float z = Matrix[2][3]/Matrix[2][2];
    float y = (Matrix[1][3] - (Matrix[1][2] * z))/Matrix[1][1];
    float x = (Matrix[0][3] - (Matrix[0][1] * y) - (Matrix[0][2] * z))/Matrix[0][0];

    cout << endl << endl;

    cout << "x : " << x << "  y : " << y << "  z : " << z << endl;










}


