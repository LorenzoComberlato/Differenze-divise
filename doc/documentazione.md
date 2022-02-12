# Progetto differenze divise

## Principio di funzionamento

Il programma si basa sull'algoritmo delle differenze divise, utilizzate in questo caso nell'interpolazione polinomiale.
Tale algoritmo si basa sul rapporto incrementale tra due punti, viene applicato poi in modo ricorsivo per punti distinti ed infine i valori ricavati vengono disposti in forma tabellare.

## Sviluppo codice

Il codice si suddivide in più parti e in più funzioni:

* creazione vettori:
    E' possibile inserire i valori dei punti da interpolare sia tramite tabella in input sia tramite terminale. Viene controllato che gli input inseriti siano coerenti con quelli richiesti, successivamente vengono convertiti in variabili float se precedentemente inseriti come frazione ed infine salvati nelle rispettive variabili.

* differenze divise:
    Qui è presente l'algoritmo principale del programma nel quale avviene un processo ricorsivo per calcolare i vari valori da stampare. I valori delle differenze divise vengono successivamente memorizzati in una matrice dinamica. Nota: ciò potrebbe essere ottimizzato procedendo con altri metodi, poichè la matrice generata contiene dei posti non utilizzati e quindi si ha uno spreco di spazio.

* queue frazioni:
    Parte di codice che utilizza le code per poter memorizzare solo i numeri inseriti in input tramite frazione; tale memorizzazione avviene in creazione vettori.

* creazione script:
    Poichè si richiede di stampare tramite gnuplot la tabella delle differenze divise, occorre creare uno script in grado di variare in base ai valori inseriti. In questa parte viene calcolata la grandezza della tebella ed infine inseriti i valori nel piano seguendo una precisa disposizione. Poichè per poter generare un .pdf con gnuplot è necessario immettere un file di ingresso, è stato generato un file "o.txt" solamente per poter poi fare il plot; non contiene nulla poichè i valori vengono immessi come label nello script.

* test:
    E' stato creato creato un main di test per poter compilare ed eseguire il programma. In esso vengono chiamate le funzioni utilizzate e cancelllate le variabili dinamiche.

* makefile:
    E' stato creato un makefile per poter compilare semplicemente immettendo il comando "make all" e se necessario, per eliminare i file creati dopo la compilazione è possibile immettere il comando "make clean".

## Suddivisione codice

Il codice è stato suddiviso in sottocartelle:

* bin: directory contenente l'eseguibile e luogo di creazione dello script, del file "o.txt" e del grafico generato in uscita da gnuplot.

* doc: directory contenente la documentazione.

* include: directory contenente gli header file. Poichè c'è questa suddivisione, per includere gli header delle varie funzioni è stato necessario specificare il percorso di tali.

* lib: directory contenente i file compilati (tranne per test poichè per scelta è stato messo nella directory test).

* src: directory contenente il codice sorgente, ovvero le varie funzioni del programma.

* test: directory contenente il main usato come esempio per come utilizzare le funzioni, il file compilato del maim e la tabella usata come input di dati.

## Compilazione

Per come compilare si consulti il file README.md.
