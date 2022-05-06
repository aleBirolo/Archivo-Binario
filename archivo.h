#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"

#define TAM_LINEA 500
#define ERR_ARCH_1 301
#define ERR_ARCH_2 302
#define ERR_ARCH_3 303
#define ERR_ARCH_4 304

#define ARCH_BIN_ALUM "estudiantes.dat"
#define ARCH_BIN_EMP "empleados.dat"
#define ARCH_BIN_MERGE "merge.dat"
#define ARCH_BIN_A_UNION_E "Alum_Union_Emp.dat"
#define ARCH_BIN_A_INTERSECTION_E "Alum_intersection_Emp.dat"
#define ARCH_BIN_A_EXCEPT_E "Alum_Except_Emp.dat"
#define ARCH_BIN_E_EXCEPT_A "Emp_Except_Alum.dat"

size_t abrirArchivo    (FILE **fp, const char *nom, const char *modo);
size_t grabarInfoEnBin (FILE *fp, const void *dato, const size_t tam, const size_t cantReg);
size_t leerInfoEnBin   (FILE *fp, void *dato, const size_t tam, const size_t cantReg);

const char * msj_error_archivo (const size_t numErr);


#endif // ARCHIVO_H_INCLUDED
