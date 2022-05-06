#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#include <stdlib.h>

#include "cadena.h"

#define TODO_OK 1
#define ERROR_PROCESO -1
#define MAXIMO(x,y) (x>=y)? x : y

typedef enum
{
    verdadero=1, falso=0
}booleano;

typedef int (*Cmp) (const void *d1, const void *d2);

void intercambio ( void *d1, void *d2, size_t tam);
void *buscar_menor (const void *d1, size_t ce, size_t tam, Cmp cmp);
void ordenar_burbujeo (void *d1, size_t ce, size_t tam, Cmp cmp);
void ordenar_seleccion (void *d1, size_t ce, size_t tam, Cmp cmp);

#endif // UTILITARIOS_H_INCLUDED

