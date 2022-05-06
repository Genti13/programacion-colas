#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM_COLA 300

typedef struct
{
    char cola[TAM_COLA];
    unsigned pri, ult, tamDisp;
} tCola;

void crearCola(tCola *p);
int colaLlena(const tCola *p, unsigned cantBytes);
int ponerEnCola(tCola *p, const void *d, unsigned cantBytes);
int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes);
int colaVacia(const tCola *p);
int sacarDeCola(tCola *p, void *d, unsigned cantBytes);
void vaciarCola(tCola *p);


#endif // COLA_H_INCLUDED
