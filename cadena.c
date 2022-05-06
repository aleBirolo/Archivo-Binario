#include "cadena.h"

void *mem_cpy(void *s1, const void *s2, size_t n)
{
    void *aux=s1;

    while ( n > 0 )
    {
        *(char *)s1=*(char *)s2;
        s1++;
        s2++;
        n--;
    }

    return aux;
}

char *str_cpy(char *s1, const char *s2)
{
    char *cad=s1;

    while (*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;

    return cad;
}

char *str_cat (char *s1, const char *s2)
{
    char *cad=s1;

    while (*s1)
        s1++;

    while (*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;

    return cad;
}

int str_cmp (const char *s1, const char *s2)
{
    while (*s1 && *s1==*s2)
    {
        s1++;
        s2++;
    }

    return *s1-*s2;
}

char *normalizar (char *cad)
{
    char *ini,
         *dest;

    ini = cad;
    dest= cad;

    while (*ini)
    {
        while (*ini && ES_BLANCO(*ini))
            ini++;

        if (*ini)
        {
            *dest = ES_MINUS(*ini) ? A_MAYUS(*ini) : *ini;
            ini++;
            dest++;

            while (*ini && !ES_BLANCO(*ini))
            {
                *dest = ES_MAYUS(*ini) ? A_MINUS(*ini) : *ini;
                ini++;
                dest++;
            }

            if (ES_BLANCO(*ini))
            {
                *dest=*ini;
                ini++;
                dest++;
            }
        }
    }

    if ( dest > cad && ES_BLANCO(*(dest-1)))
            dest--;
    *dest='\0';

    return cad;
}

int str_len (const char *s)
{
    int n=0;
    while (*s)
    {
        s++;
        n++;
    }
    return n;
}
