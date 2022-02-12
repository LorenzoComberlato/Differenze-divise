# Progetto differenze divise

### NOTA: 
Per poter visualizzare il grafico generato è necessario installare nel proprio computer gnuplot.

Nella cartella doc è presente la documentazione del codice dove vengono specificate le funzionalità e caratteristiche del codice.

Tale progetto può essere migliorato e reso più efficiente utilizzando altri metodi.

### [La cartella condivisa presenta il codice già compilato e il plot già generato, se si desidera ricompilare, partendo dalla cartella principale eseguire nel terminale "make all". Se invece si desidera eliminare i file generati in compilazione eseguire "make clean". Seguire poi le istruzioni seguenti.]

## Istruzioni d'uso

Dopo aver installato le varie cartelle nella propria area di lavoro e letto la documentazione del codice, è possibile iniziare con la compilazione e generazione dei file.

Partendo dalla cartella principale, è possibile compilare il programma tramite il comando "make all" il quale genera i file necessari (eseguibile e file compilati) all'utilizzo, altrimenti se non si vuole utilizzare il makefile è necessario utilizzare il comando g++ inserendo i nomi di tutti i file .cc ponendo attenzione ad inserire il percorso corretto.

Dopo aver copilato si saranno generati dei file nelle cartelle bin, lib e test. Per poter eseguire il file è necessario entrare nella sottocartella /bin.

Il programma permette di avere in input sia un file txt sia valori immessi da terminare:
* tramite file txt:

    Per eseguire il programma, eseguire il file test (nella cartella bin) seguito dal nome del file contenente i valori scrivendo il percorso corretto:
    
    esempio di compilazione:
    ```
        ./test ../test/tabella_input.txt
    ```
    E' stato creato un file d'esempio in test chiamato "tabella_input.txt". Per importare altre tabelle basta inserirle nella sottocartella /test.
    Per costruirsi la propria tabella è necessario prima di tutto inserire il numero di punti che si vogliono interpolare, successivamente basterà scrivere per ogni riga il valore del punto X correlato al punto Y.

    Esempio:
    ``` 
    5
    -3/2    -14.1014
    -3/4    -0.931596
    0       0
    3/4     0.931596
    3/2     14.1014
    ``` 

* inserendo valori dal terminale:

    Se non si vuole immettere valori da tabella, bensì da terminale, basterà specificare innanzitutto il numero di punti, ed infine il valore dei vari punti X e Y.

Successivamente si creerà un file script ed un file "o.txt" utilizzato per generare il plot. Ora dopo aver installato nel proprio computer gnuplot, inserendo da terminale:
```
gnuplot script
```
Nella cartella /bin si creerà un file chiamato "plot.pdf", una volta aperto sarà possibile visualizzare la tabella completa delle differenze divise. (Nota: se il file .pdf non si apre al primo tentativo, riprovare ad aprirlo).

Se si desidera, tramite il comando "make clean" è possibile eliminare i file generati dopo la compilazione, compreso lo script e il plot.
(Nota: i comandi make devono essere utilizzati quando ci si trova nella cartella principale).

