#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::to_string;

#include "../include/creazione_vettori.hpp"
#include "../include/queue_frazioni.hpp"

double numero_inserito(char *input, bool is_x, int index, queue &q_x, queue &q_y);
bool controlla_formato_input(char *input, bool &slash);

int inserimento_punti(double *&X, double *&Y, queue &q_x, queue &q_y, char *nome_file)
{
    int numero_punti = 0;

    char *buffer = new char[CIFRE_MASSIME];
    ifstream input_file(nome_file);
    if (!input_file.fail())
    {                               // Nel caso in cui si sia potuto aprire il file, si va a prendere l'input al suo interno
        input_file >> numero_punti; // Il primo elemento contenuto nel file e' il numero di punti presenti
        X = new double[numero_punti];
        Y = new double[numero_punti];
        for (int i = 0; i < numero_punti; i++)
        {
            if (input_file.eof())
            {
                cerr << "Il file non e' formato correttamente in quanto contiene meno punti di quanto specificato" << endl;
                exit(EXIT_FAILURE);
            }
            input_file >> buffer;
            X[i] = numero_inserito(buffer, true, i, q_x, q_y);

            input_file >> buffer;
            Y[i] = numero_inserito(buffer, false, i, q_x, q_y);
        }
    }
    else
    {
        cout << "Non e' stato specificato alcun file di testo da cui importare i dati. Si proceda all'inserimento manuale." << endl
             << "Inserire il numero di punti: ";
        cin >> numero_punti;
        X = new double[numero_punti];
        Y = new double[numero_punti];
        for (int i = 0; i < numero_punti; i++)
        {
            cout << "Inserire il punto X_" << i << ": ";
            cin >> buffer;
            X[i] = numero_inserito(buffer, true, i, q_x, q_y);
            cout << "Inserire il punto Y_" << i << ": ";
            cin >> buffer;
            Y[i] = numero_inserito(buffer, false, i, q_x, q_y);
        }
    }
    delete[] buffer;
    return numero_punti;
}

bool controlla_formato_input(char *input, bool &slash)
{
    // Scorro una volta l'intera stringa per controllare che l'utente abbia inserito un formato accettabile
    int contatore_slash = 0;
    int contatore_punti = 0;
    if (input[0] == '\0')
        return false; // L'input non può essere vuoto
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            if (input[i] == '/')
                contatore_slash++;
            else if (input[i] == '.')
                contatore_punti++;
            else
                return false; // Se è presente un carattere che non è un numero, un punto o uno slash, l'input non è accettabile
        }
        if (contatore_punti > 1 || contatore_slash > 1)
            return false; // Se c'è più di un punto o più di uno slash, l'input non è accettabile
        if (contatore_punti > 0 && contatore_slash > 0)
            return false; // Non avrebbe senso che un numero venga espresso come frazione di numeri decimali con notazione con punto decimale
    }
    slash = contatore_slash; // L'assegnazione funziona perché anche se il contatore è un int, può valere solo o 0 o 1 per i controlli eseguiti precedentemente
    return true;
}

double numero_inserito(char *input, bool is_x, int index, queue &q_x, queue &q_y)
{
    bool is_negative = input[0] == '-';
    if (is_negative)
        input += 1;
    bool slash = false; // flag che indica se nell'input è presente un numero espresso come frazione numeratore/denominatore
    if (!controlla_formato_input(input, slash))
    {
        cerr << "I dati inseriti dall'utente non rispettano il formato richiesto. Si possono inserire solo numeri interi e deciamli, questi ultimi espressi sia con la notazione con punto decimale sia con la frazione numeratore/denominatore." << endl;
        exit(EXIT_FAILURE);
    }
    // Se arrivo qui vuol dire che il controllo ha avuto esito positivo quindi posso continuare con la conversione senza altri controlli
    double risultato = 0;
    if (slash)
    {
        int numeratore = 0, denominatore = 1;
        bool passato_separatore = false;

        for (int i = 0; input[i] |= '\0'; i++)
        {
            if (!passato_separatore && input[i] != '/')
            {
                numeratore = numeratore * 10 + input[i] - '0';
            }
            if (passato_separatore)
            {
                denominatore = denominatore * 10 + input[i] - '0';
            }
            if (!passato_separatore && input[i] == '/')
            {
                denominatore = 0;
                passato_separatore = true;
            }
        }
        risultato = ((double)numeratore) / denominatore;
        if (is_x)
        {
            enqueue((is_negative ? "-" : "") + (to_string(numeratore) + "/" + to_string(denominatore)), index, q_x);
        }
        else
        {
            enqueue((is_negative ? "-" : "") + (to_string(numeratore) + "/" + to_string(denominatore)), index, q_y);
        }
    }
    else
    {
        risultato = atof(input);
    }

    return risultato * (is_negative ? -1 : 1);
}
/*
void stampa_arrays(int numero_punti, double* X, double* Y) {
    cout << endl << "Sono stati inseriti " << numero_punti << " punti." << endl <<"Stampa vettori formati: " << endl;
    for (int i = 0; i < numero_punti; i++) {
        cout << 'X' << i << ":\t" << X[i] << "\t\t" << 'Y' << i << ":\t" << Y[i] << endl;
    }
}
*/
