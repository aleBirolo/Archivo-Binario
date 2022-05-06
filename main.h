#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "archivo.h"
#include "persona.h"
#include "menu.h"

#define MSJ_CREAR "creado"
#define MSJ_ABRIR "abierto"
#define MSJ_CREAR_ABRIR "creado/abierto"
#define MSJ_CARGAR "cargado"
#define MSJ_ACTUALIZAR "actualizado"
#define MSJ_MERGE "mergeado"
#define MSJ_UNION "unido"
#define MSJ_INTERSECCION "intersectado"
#define MSJ_EXCEPCION "excluisivo"

void ordenarLote(void *d,size_t ce, size_t tam, size_t tipoOrd, Cmp cmp);

void msj_de_retorno_archivo (const int ret, const char *nom, const char *msj);
void msj_de_retorno_proceso(const int ret, const char *nom, const char *msj);

int mergear (FILE *fpAlum, FILE *fpEmp, FILE *fpMerge);
int unir (FILE *fpAlum, FILE *fpEmp, FILE *fpUnion);
int interseccion (FILE *fpAlum, FILE *fpEmp, FILE *fpIntersection);
int excluir (FILE *fpX, size_t tamX, FILE *fpY, size_t tamY, FILE *fpExcep);

void mostrarArchivoPersona(FILE *fp);
void mostrarArchivoAlumnos(FILE *fpAlum);
void mostrarArchivoEmpleados(FILE *fpEmp);


#endif // MAIN_H_INCLUDED
