#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ofstream;
using std::string;

#include "../include/queue_frazioni.hpp"
#include "../include/creazione_script.hpp"

void stampa_script(int numero_punti, double *X, double *Y, double *DD[], queue &q_x, queue &q_y)
{
    string str;
    const string fname = "o.txt";
    ofstream O(fname);
    O << 0;
    O.close();

    ofstream output("script");
    output << "set terminal pdf size 8,5"
              "\nset output 'plot.pdf'\n\n"
              "set xrange [ 0 : "
           << numero_punti + 2 << " ]\n"
                                  "set yrange [ 0 : "
           << (numero_punti * 2) + 2 << " ]\n\n"
                                        "unset border\n"
                                        "unset xtics\n"
                                        "unset ytics\n\n";

    int n_label = numero_punti;
    int tmp = numero_punti;
    while (tmp > 0)
    {
        n_label += tmp;
        tmp--;
    }

    int x_position = 1,
        y_position = numero_punti * 2;

    int n = 1;
    for (int j = 0; j < numero_punti; j++)
    { // vettore X
        if (first(str, q_x) == j)
        {
            output << "set label " << n << " '" << str << "' at " << x_position << "," << y_position << endl;
            dequeue(q_x);
            y_position -= 2;
            n++;
        }
        else
        {
            output << "set label " << n << " '" << X[j] << "' at " << x_position << "," << y_position << endl;
            y_position -= 2;
            n++;
        }
    }
    output << "\n";
    x_position++;
    y_position = numero_punti * 2;

    for (int j = 0; j < numero_punti; j++)
    { // vettore Y
        if (first(str, q_y) == j)
        {
            output << "set label " << n << " '" << str << "' at " << x_position << "," << y_position << endl;
            dequeue(q_y);
            y_position -= 2;
            n++;
        }
        else
        {
            output << "set label " << n << " '" << Y[j] << "' at " << x_position << "," << y_position << endl;
            y_position -= 2;
            n++;
        }
    }
    output << "\n";
    x_position++;
    y_position = (numero_punti * 2) - 1;
    int counter = y_position;

    int pos = numero_punti - 1;
    for (int k = 0; k < numero_punti - 1; k++)
    {
        for (int j = 0, s = 0; j < numero_punti - 1; j++, s++)
        { // matrice DD
            if (s < pos)
            {
                output << "set label " << n << " '" << DD[j][k] << "' at " << x_position << "," << y_position << endl;
                y_position -= 2;
                n++;
            }
        }
        counter--;
        output << "\n";
        y_position = counter;
        pos--;
        x_position++;
    }
    output << "plot 'o.txt' title '' with points pointtype -1";

    output.close();
}