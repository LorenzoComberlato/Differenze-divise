#include <iostream>

using std::cout;
using std::endl;

#include "../include/differenze_divise.hpp"

void differenze_divise(int numero_punti, double *X, double *Y, double **&DD)
{

    DD = new double *[numero_punti - 1];
    for (int i = 0; i < numero_punti - 1; i++)
    {
        DD[i] = new double[numero_punti - 1];
    }
    for (int i = 0, k = 1; i < numero_punti - 1; i++, k++)
    {
        DD[i][0] = ((Y[k] - Y[k - 1]) / (X[k] - X[k - 1]));
    }
    int tmp = numero_punti - 1;
    for (int j = 1; j < numero_punti - 1; j++)
    {
        for (int i = 0, k = 1, h = j + 1; i < numero_punti - 1; i++, k++, h++)
        {
            if (k < tmp)
            {
                DD[i][j] = ((DD[k][j - 1] - DD[k - 1][j - 1]) / (X[h] - X[h - j - 1]));
            }
        }
        tmp--;
    }
    // codice per debugging
    /*
    cout << "il risultato delle differenze divise e' : "<<endl;
    tmp=numero_punti-1;
    for(int j = 0; j < numero_punti-1; j++){
        for(int i = 0, k = 0; i < numero_punti-1; i++, k++){
            if( k < tmp ){
                cout << DD[j][i] << " \t";
                if( DD[j][i] == 0){
                    cout << " \t";
                }
            }
        }
        tmp--;
        cout << endl;
    }
    */
}