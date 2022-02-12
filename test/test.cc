#include "../include/creazione_vettori.hpp"
#include "../include/differenze_divise.hpp"
#include "../include/queue_frazioni.hpp"
#include "../include/creazione_script.hpp"

int main(int argc, char *argv[])
{

    queue q_x, q_y;
    init(q_x);
    init(q_y);

    double *X, *Y, **DD;
    int numero_punti = inserimento_punti(X, Y, q_x, q_y, (char *)(argc == 1 ? nullptr : argv[1])); // Solo per provare le funzioni: se l'utente ha dato come parametro al programma il nome di un file allora si usa quello per l'input

    // stampa_arrays(numero_punti, X, Y);

    differenze_divise(numero_punti, X, Y, DD);

    stampa_script(numero_punti, X, Y, DD, q_x, q_y);

    for (int i = 0; i < numero_punti - 1; i++)
    {
        delete[] DD[i];
    }
    delete[] DD;
    delete[] X;
    delete[] Y;
    deinit(q_x);
    deinit(q_y);

    return 0;
}
