#ifndef CREAZIONE_VETTORI_HPP
#define CREAZIONE_VETTORI_HPP
#include "queue_frazioni.hpp"
#define CIFRE_MASSIME 10 // Cifre massime di cui sono composti i numeri inseriti dall'utente. Il limite massimo è il limite di un signed int a 32 bit

int inserimento_punti(double *&X, double *&Y, queue &q_x, queue &q_y, char *nome_file = nullptr);
void stampa_arrays(int numero_punti, double *X, double *Y);
void differenze_divise(int numero_punti, double *X, double *Y);

#endif
