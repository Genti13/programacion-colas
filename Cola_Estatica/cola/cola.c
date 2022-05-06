#include "cola.h"
#include <string.h>
#define minimo(X,Y) ( (X) <= (Y) ? (X) : (Y) )

void crearCola(tCola *p)
{
    p->pri = TAM_COLA;
    p->ult = TAM_COLA;
    p->tamDisp = TAM_COLA;
}

int colaLlena(const tCola *p, unsigned cantBytes)
{
    return p->tamDisp < cantBytes + sizeof(unsigned);
}

int ponerEnCola(tCola *p, const void *d, unsigned cantBytes)
{
    unsigned ini, fin;

    if(p->tamDisp < sizeof(unsigned) + cantBytes) //Si la cola esta llena
    {
        return 0;
    }

    p->tamDisp -= sizeof(unsigned) + cantBytes; //como voy a agregar, redusco el tamano disponible

    /**Parte 1**/
    //Parte 1 Pone primero el tamano de los bytes
    if((ini = minimo(sizeof(cantBytes), TAM_COLA - p->ult)) != 0)
    {
        memcpy(p->cola + p->ult, &cantBytes, ini);
    }

    if((fin = sizeof(cantBytes)-ini) != 0)
    {
        memcpy(p->cola, ((char *)&cantBytes) + ini,fin);
    }

    /**END_Parte 1**/

    p->ult = fin ? fin : p->ult + ini;

    /**Parte 2**/
    //Parte 2 Pone despues la data (d)
    if((ini = minimo(cantBytes, TAM_COLA - p->ult))!= 0)
    {
        memcpy(p->cola + p->ult, d, ini);
    }

    if((fin = cantBytes - ini) != 0)
    {
        memcpy(p->cola, ((char*)d) + ini, fin);
    }
    /**END_Parte 2**/
    p->ult = fin ? fin : p->ult + ini;

    return 1;
}

int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo,ini,fin,pos = p->pri;

    if(p->tamDisp == TAM_COLA)
    {
        return 0;
    }

    if((ini = minimo(sizeof(unsigned),TAM_COLA - pos)) != 0)
    {
        memcpy(&tamInfo, p->cola + pos, ini);
    }

    if((fin = sizeof(unsigned) - ini) != 0)
    {
        memcpy(((char*) &tamInfo) + ini, p->cola, fin);
    }

    pos = fin ? fin : pos + ini;
    tamInfo = minimo(tamInfo, cantBytes);

    if((ini = sizeof(unsigned) - ini) != 0)
    {
        memcpy(d, p-> cola + pos, ini);
    }

    if((fin = tamInfo - ini) != 0)
    {
        memcpy(((char *)d) + ini, p->cola, fin);
    }

    return 1;
}

int colaVacia(const tCola *p)
{
    return p->tamDisp == TAM_COLA;
}

int sacarDeCola(tCola *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo, ini, fin;

    if(p->tamDisp == TAM_COLA)
    {
        return 0;
    }

    if((ini = minimo(sizeof(unsigned), TAM_COLA - p->pri)) != 0)
    {
        memcpy(&tamInfo, p->cola + p->pri, ini);
    }
    if((fin = sizeof(unsigned) - ini) != 0)
    {
        memcpy(((char*)&tamInfo) + ini, p->cola, fin);
    }

    p->pri = fin ? fin : p-> pri + ini;
    p->tamDisp += sizeof(unsigned) + tamInfo;
    tamInfo = minimo(tamInfo, cantBytes);

    if((ini = minimo(tamInfo, TAM_COLA - p->pri)) != 0)
    {
        memcpy(d, p->cola + p->pri, ini);
    }
    if((fin = tamInfo - ini) != 0)
    {
        memcpy(((char *)d) + ini, p->cola, fin);
    }

    p->pri = fin ? fin : p->pri + ini;

    return 1;
}

void vaciarCola(tCola *p)
{
    p->ult = p->pri;
    p->tamDisp = TAM_COLA;
}
