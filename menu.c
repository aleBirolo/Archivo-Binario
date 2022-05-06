#include "menu.h"

void menuSemilla()
{
    int tipoSemilla;

    do{
        printf ("\n\t Opciones de semilla \n\n"
                " 0 = Estatica (Al volver a iniciar el programa se generan las mismas secuencias. No sirve con reiniciar)\n"
                " 1 = Dinamica\n"
                "\n Ingrese opcion: ");
        scanf("%d", &tipoSemilla);

        if (tipoSemilla == 1)
            srand(time(NULL));
        else
            if (tipoSemilla != 0)
            {
                printf ("\n Error opcion invalida. ");
                system("pause");

            }
        system("cls");
    }while ( tipoSemilla < 0 || tipoSemilla > 1);

}

int menuCantidad(char *nom, int topeCant)
{
    int cant;

    do{
        printf ("\n\t Definicion de cantidades del lote:\n");
        printf ("\n Ingrese la cantidad de registros para el archivo %s (max:%d): ",nom ,topeCant);
        scanf("%d", &cant);
        if (cant < 0 || cant > topeCant)
        {
            printf ("\n Error. ");
            system("pause");
        }
        system("cls");
    }while ( cant < 0 || cant > topeCant);

    return cant;

}

int menuOrdenamiento()
{
    int tipoOrdenamiento;

    do{
        printf ("\n\t Opciones de ordenamiento \n\n"
                " 0 = Burbujeo \n"
                " 1 = Seleccion\n"
                " 2 = QSORT(Libreria)\n"
                "\n Ingrese opcion: ");
        scanf("%d", &tipoOrdenamiento);

        if (tipoOrdenamiento < 0 || tipoOrdenamiento >2)
        {
                printf ("\n Error opcion invalida. ");
                system("pause");
        }
        system("cls");
    }while ( tipoOrdenamiento < 0 || tipoOrdenamiento >2);

    return tipoOrdenamiento;
}

void mostrarOpciones()
{
    printf ("\n\t Menu \n\n"
            "  %d: Crear alumnos y empleados (en base a la misma persona) \n"
            "  %d: Crear/Agregar alumnos\n"
            "  %d: Crear/Agregar empleados\n"
            "  %d: Mergear archivos\n"
            "  %d: Alumnos union empleados \n"
            "  %d: Alumnos intersection empleados \n"
            "  %d: Alumnos except empleados \n"
            "  %d: Empleados except alumnos \n"
            "  %d: Mostrar archivos\n"
            " %d: Eliminar archivos\n"
            " %d: Reiniciar Programa\n"
            "  %d: Salir\n"
            ,Crear_alumnos_y_empleados
            ,Crear_Agregar_alumnos
            ,Crear_Agregar_empleados
            ,Mergear_archivos
            ,Alumnos_union_empleados
            ,Alumnos_intersection_empleados
            ,Alumnos_except_empleados
            ,Empleados_except_alumnos
            ,Mostrar_archivos
            ,Eliminar_archivos
            ,Reiniciar_Programa
            ,Salir);
}

int menu()
{
    int opc;

    do{
        mostrarOpciones();
        printf ("\n Ingrese Opcion: ");
        scanf("%d", &opc);

        if (OPCION_INV(opc))
        {
            printf ("\n Opcion invalida. ");
            system("pause");
        }
        system("cls");
    }while (OPCION_INV(opc));

    return opc;
}
