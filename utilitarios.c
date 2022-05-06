#include "utilitarios.h"

void intercambio ( void *d1, void *d2, size_t tam)
{
   void *aux = malloc (tam);

   if (!aux)
        return;

   mem_cpy(aux, d1,tam);
   mem_cpy(d1, d2, tam);
   mem_cpy(d2, aux, tam);

   free(aux);
}

void *buscar_menor (const void *d1, size_t ce, size_t tam, Cmp cmp)
{
    void *elMenor = (void *)d1;
    int i;

    for (i=0; i<ce-1 ; i++, d1+=tam)
            if (cmp( d1, elMenor)  < 0)
                elMenor=(void *)d1;

    return elMenor;
}

void ordenar_burbujeo (void *d1, size_t ce, size_t tam, Cmp cmp)
{
    void *aux=d1;
    int i,
        j;

    for (i=0; i< ce; i++)
    {
        d1=aux;
        for (j=0; j<ce-1 ; j++, d1+=tam)
            if (cmp( d1, (d1+tam))  > 0)
                intercambio( d1, (d1+tam), tam );
    }

}

void ordenar_seleccion (void *d1, size_t ce, size_t tam, Cmp cmp)
{
    void *elMenor = d1;
    int i;

    for ( i=0 ; i<ce; i++, d1+=tam)
    {
        /// Aca el tam de lote es ce+1-i por que:
        /// En el primer paso ce=10, i=1 y el tam que
        /// estoy pasando es de 9, cuando deberia ser 10
        elMenor= buscar_menor(d1,ce+1-i,tam,cmp);
        intercambio(d1,elMenor,tam);
    }
}
