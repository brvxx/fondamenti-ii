/** @file
Questo file contiene la definizione di `ElemType` per il tipo `int vector` e la
documentazione delle funzioni a esso associate.
*/

#ifndef ELEMTYPE_INT_VECTOR_H_
#define ELEMTYPE_INT_VECTOR_H_

#include <stdbool.h>
#include <stdio.h>

/** @brief Definizione di `struct ElemType`. */
struct ElemType{
    int *data; /*!< Puntatore ai dati del vettore. */
    size_t size; /*!< Dimensione del vettore, ovvero numero di `int` che questo contiene. */
};
/** @brief Definizione di un nome alternativo per `struct ElemType`. */
typedef struct ElemType ElemType;

/** @brief La funzione `ElemCompare()` confronta due elementi utilizzando una 
        definizione di ordinameto per i "vettori di int" analoga a quella 
        definita per le stringe C.

@param[in] e1 Puntatore al primo elemento di cui eseguire il confronto. Il
              valore contenuto in `e1` non viene modificato.
@param[in] e2 Puntatore al secondo elemento di cui eseguire il confronto. Il
              valore contenuto in `e2` non viene modificato.

@return La funzione ritorna un valore intero che indica la relazione tra i due
        elementi, ovvero:
         - "-1" se il contenuto del primo è minore di quello del secondo, ovvero 
            se il primo valore che non corrisponde è più piccolo in `e1` che in `e2`;
         - "0" se i contenuti dei due vettori sono uguali;
         - "1" se il contenuto del primo è maggiore di quello del secondo, ovvero 
            se il primo valore che non corrisponde è più grande in `e1` che in `e2`.
*/
int ElemCompare(const ElemType *e1, const ElemType *e2);

/** @brief La funzione `ElemCopy()` crea e ritorna una copia dell'elemento dato.

@param[in] e Puntatore all'elemento da copiare. Il valore contenuto in `e` non
             viene modificato.

@return Copia dell'elemento `e`.
*/
ElemType ElemCopy(const ElemType *e);

/** @brief La funzione `ElemDelete()` libera la memoria occupata dall'elemento
           specificato.

@param[in] e Puntatore all'elemento di cui liberare la memoria.

@return Non ci sono valori di ritorno.
*/
void ElemDelete(ElemType *e);

/** @brief La funzione `ElemRead()` legge un elemento da file, ovvero legge la sua
           `size` e, dopo aver alloca spazio a sufficienza, legge `size` interi 
           scrivendoli nel vettore puntato da `data`. Se la lettura di 
           anche solo uno dei valori fallisce la funzione ritorna `0`, altrimenti 
           ritorna `1`.

@param[in] f `FILE *` da cui leggere un elemento.
@param[out] e Elemento letto da file.

@return Numero di elementi effettivamente letti (`0` o `1`).
*/
int ElemRead(FILE *f, ElemType *e);

/** @brief La funzione `ElemReadStdin()` legge un elemento da standard input, 
           ovvero legge la sua `size` e, dopo aver alloca spazio a sufficienza, 
           legge `size` interi scrivendoli nel vettore puntato da `data`.
           Se la lettura di anche solo uno dei valori fallisce la funzione 
           ritorna `0`, altrimenti ritorna `1`.

@param[out] e Elemento letto da standard input.

@return Numero di elementi effettivamente letti (`0` o `1`).
*/
int ElemReadStdin(ElemType *e);

/** @brief La funzione `ElemWrite()` stampa un elemento su file.

@param[in] e Puntatore all'elemento da stampare su file. Il valore contenuto in
             e non viene modificato.
@param[in] f `FILE *` su cui stampare l'elemento.

@return Non ci sono valori di ritorno.
*/
void ElemWrite(const ElemType *e, FILE *f);

/** @brief La funzione `ElemWriteStdout()` stampa un elemento su `stdout`.

@param[in] e Puntatore all'elemento da stampare su standard output. Il valore
             contenuto in e non viene modificato.

@return Non ci sono valori di ritorno.
*/
void ElemWriteStdout(const ElemType *e);


#endif // ELEMTYPE_INT_VECTOR_H_
