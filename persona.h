#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "cadena.h"
#include "utilitarios.h"

#define TAM_NOMBRE 60
#define TAM_APELLIDO 50
#define TAM_NOTAS 4 /// 3 notas, 1 Promedio

#define TAM_LOTE_ALU 1000
#define TAM_LOTE_EMP 1000
#define TAM_LOTE_PER (TAM_LOTE_ALU > TAM_LOTE_EMP) ? TAM_LOTE_ALU : TAM_LOTE_EMP
#define CANT_NOM_MASC 99
#define CANT_NOM_FEME 99
#define CANT_APE 299


typedef struct
{
    unsigned dni;
    char sexo;
    char ape[TAM_APELLIDO],
         nom[TAM_NOMBRE];
}t_persona;

typedef struct
{
    unsigned dni;
    char sexo;
    char ape[TAM_APELLIDO],
         nom[TAM_NOMBRE];
    float notas[TAM_NOTAS];
    char mensaje[30]; /// solo para ayudar en la visualizacion
}t_alumno;

typedef struct
{
    unsigned dni;
    char sexo;
    char ape[TAM_APELLIDO],
         nom[TAM_NOMBRE];
    double sueldo;
    char mensaje[30]; /// solo para ayudar en la visualizacion
}t_empleado;

typedef enum
{
    Masculino='M', Femenino='F'
}tipoSexo;

typedef enum
{
    nota_1=0, nota_2=1, nota_3=2, promedio=3
}enum_notas;

void crearLotePersonas (t_persona *per, size_t tamLote);
void cargarLoteAlumnos (t_alumno *alum,t_persona *per,size_t ini, size_t tamLote);
void cargarLoteEmpleados (t_empleado *emp,t_persona *per,size_t ini, size_t tamLote);

void mostrarPersonas (t_persona *per, int pos);
void mostrarAlumnos (t_alumno *alum, int pos);
void mostrarEmpleados (t_empleado *emp, int pos);

int comparaPersonas (const void *d1, const  void *d2);

void vaciarLotePersonas(t_persona *per, size_t tamLote);

#endif // PERSONA_H_INCLUDED
