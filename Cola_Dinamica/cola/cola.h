#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define minimo(X,Y) ((X) <= (Y) ? (X) : (Y) )

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef struct
{
    tNodo *pri,
          *ult;
}tCola;

void crearCola(tCola *p);
int colaVacia(const tCola *p);
int colaLlena(const tCola *p,  unsigned cantBytes);
void vaciarCola(tCola *p);

int ponerEnCola(tCola * p, void * d, unsigned  cantBytes);
int sacarDeCola(tCola * p, void * d, unsigned cantBytes);
int verPrimeroCola(const tCola * p, void * d, unsigned cantBytes);

#endif // COLA_H_INCLUDED
