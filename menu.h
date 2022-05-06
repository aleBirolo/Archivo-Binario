#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MENU 11
#define OPCION_INV(x) (!(0<=x && x<=TAM_MENU-1) && x!=99)
#define SALIR 0

typedef enum
{
    Crear_alumnos_y_empleados = 1,
    Crear_Agregar_alumnos = 2,
    Crear_Agregar_empleados = 3,
    Mergear_archivos = 4,
    Alumnos_union_empleados = 5,
    Alumnos_intersection_empleados = 6,
    Alumnos_except_empleados = 7,
    Empleados_except_alumnos = 8,
    Mostrar_archivos = 9,
    Eliminar_archivos = 10,
    Reiniciar_Programa = 99,
    Salir=0
}enum_menu;

void menuSemilla();
int menuCantidad(char *nom, int topeCant);
int menuOrdenamiento();

void mostrarOpciones();
int menu();

#endif // MENU_H_INCLUDED
