#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdlib.h>

#define ES_BLANCO(x) (x==' ' || x=='\t' || x=='\n')
#define ES_MINUS(x) ('a'<= x && x<='z')
#define ES_MAYUS(x) ('A'<=x && x<='Z')
#define ES_LETRA(x) ( ES_MINUS(x) || ES_MAYUS(x))
#define A_MAYUS(x) (x-' ')
#define A_MINUS(x) (x+' ')

void *mem_cpy(void *s1, const void *s2, size_t n);

char *str_cpy(char *s1, const char *s2);
char *str_cat (char *s1, const char *s2);
int str_cmp (const char *s1, const char *s2);
int str_len (const char *s);
char *normalizar (char *cad);

#endif // CADENA_H_INCLUDED
