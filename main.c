#include "main.h"

int main()
{
    int opc,
        cantAlum=0,
        cantEmp=0,
        cantAlum_nuevos,
        cantEmp_nuevos,
        tipoOrdenamiento,
        ret=TODO_OK,
        retTotal=TODO_OK;

    t_persona personaLote[TAM_LOTE_PER]={};
    t_alumno alumLote[TAM_LOTE_ALU]={};
    t_empleado empLote[TAM_LOTE_EMP]={};

    /// Si quiero que abrir archivo funciones con FILE *
    /// tengo que pedir memoria antes con malloc
    FILE *fpAlum,
         *fpEmp,
         *fpMerge,
         *fpUnion,
         *fpIntersection,
         *fp_A_exp_E,
         *fp_E_exp_A;

    menuSemilla();
    tipoOrdenamiento = menuOrdenamiento();

    opc = menu();

    while (opc != SALIR)
    {
        switch (opc)
        {
            case Crear_alumnos_y_empleados:

                /// Definicion de cantidades
                cantAlum = menuCantidad(ARCH_BIN_ALUM, TAM_LOTE_ALU);
                cantEmp = menuCantidad(ARCH_BIN_EMP, TAM_LOTE_EMP);

                /// Generacion del lote
                crearLotePersonas(personaLote, MAXIMO(cantAlum, cantEmp));
                ordenarLote(personaLote,MAXIMO(cantAlum, cantEmp),sizeof(t_persona), tipoOrdenamiento,comparaPersonas);
                cargarLoteAlumnos(alumLote, personaLote,0, cantAlum);
                cargarLoteEmpleados(empLote, personaLote,0, cantEmp);

                /// Creacion del archivo de alumnos
                ret = abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "wb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_CREAR );

                /// Carga del archivo de alumnos
                if ( ret == TODO_OK )
                {
                    ret=grabarInfoEnBin(fpAlum, &alumLote, sizeof(t_alumno)*cantAlum,1);
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_CARGAR );
                }

                /// Creacion del archivo de empleados
                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "wb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_CREAR );

                /// Carga del archivo de empleados
                if ( ret == TODO_OK )
                {
                   ret=grabarInfoEnBin(fpEmp, &empLote, sizeof(t_empleado)*cantEmp,1);
                   retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                   msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_CARGAR );
                }

                if (retTotal == TODO_OK)
                    printf("\n Lote cargado y archivos generados exitosamente.\n");
                else
                    printf ("\n Error en la creacion del lote\n");

                fclose(fpAlum);
                fclose(fpEmp);

                break;

            case Crear_Agregar_alumnos:

                if (cantAlum != 0)
                    vaciarLotePersonas(personaLote, MAXIMO(cantAlum, cantEmp));

                cantAlum_nuevos= menuCantidad(ARCH_BIN_ALUM, TAM_LOTE_ALU-cantAlum);
                cantAlum+=cantAlum_nuevos;

                crearLotePersonas(personaLote, cantAlum_nuevos);

                cargarLoteAlumnos(alumLote, personaLote, cantAlum - cantAlum_nuevos, cantAlum);
                ordenarLote(alumLote,cantAlum,sizeof(t_alumno), tipoOrdenamiento,comparaPersonas);

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "wb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_CREAR_ABRIR);

                if ( ret == TODO_OK)
                {
                    ret=grabarInfoEnBin(fpAlum, &alumLote, sizeof(t_alumno)*cantAlum,1);
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret,ARCH_BIN_ALUM, MSJ_ACTUALIZAR );
                }

                if (retTotal == TODO_OK)
                    printf("\n Lote cargado y archivo actualizado exitosamente.\n");
                else
                    printf ("\n Error en la actualizacion del archivo\n");

                fclose(fpAlum);

                break;

            case Crear_Agregar_empleados:

                if ( cantEmp != 0)
                    vaciarLotePersonas(personaLote, MAXIMO(cantAlum, cantEmp));

                cantEmp_nuevos= menuCantidad(ARCH_BIN_EMP, TAM_LOTE_EMP-cantEmp);
                cantEmp+=cantEmp_nuevos;

                crearLotePersonas(personaLote, cantEmp_nuevos);

                cargarLoteEmpleados(empLote, personaLote, cantEmp - cantEmp_nuevos, cantEmp);
                ordenarLote(empLote,cantEmp,sizeof(t_empleado), tipoOrdenamiento,comparaPersonas);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "wb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_CREAR_ABRIR);
                if ( ret == TODO_OK)
                {
                    ret=grabarInfoEnBin(fpEmp, &empLote, sizeof(t_empleado)*cantEmp,1);
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ACTUALIZAR);
                }

                if (retTotal == TODO_OK)
                    printf("\n Lote cargado y archivo actualizado exitosamente.\n");
                else
                    printf ("\n Error en la actualizacion del archivo\n");

                fclose(fpEmp);

                break;

            case Mergear_archivos:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_ABRIR);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ABRIR);

                if ( retTotal == TODO_OK )
                {
                    ret= abrirArchivo(&fpMerge, ARCH_BIN_MERGE, "wb");
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_MERGE, MSJ_CREAR);

                    if ( retTotal == TODO_OK )
                    {
                        ret = mergear (fpAlum, fpEmp, fpMerge);
                        retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                        msj_de_retorno_proceso(ret, ARCH_BIN_MERGE, MSJ_MERGE);
                    }

                    fclose(fpMerge);
                }

                fclose(fpAlum);
                fclose(fpEmp);

                break;

            case Alumnos_union_empleados:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_ABRIR);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ABRIR);

                if ( retTotal == TODO_OK )
                {
                    ret= abrirArchivo(&fpUnion, ARCH_BIN_A_UNION_E, "wb");
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_A_UNION_E, MSJ_CREAR);

                    if ( retTotal == TODO_OK )
                    {
                        ret = unir (fpAlum, fpEmp, fpUnion);
                        retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                        msj_de_retorno_proceso(ret, ARCH_BIN_A_UNION_E, MSJ_UNION);
                    }

                    fclose(fpUnion);
                }

                fclose(fpAlum);
                fclose(fpEmp);

                break;

            case Alumnos_intersection_empleados:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_ABRIR);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ABRIR);

                if ( retTotal == TODO_OK )
                {
                    ret= abrirArchivo(&fpIntersection, ARCH_BIN_A_INTERSECTION_E, "wb");
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_A_INTERSECTION_E, MSJ_CREAR);

                    if ( retTotal == TODO_OK )
                    {
                        ret = interseccion (fpAlum, fpEmp, fpIntersection);
                        retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                        msj_de_retorno_proceso(ret, ARCH_BIN_A_INTERSECTION_E, MSJ_INTERSECCION);
                    }

                    fclose(fpIntersection);
                }

                fclose(fpAlum);
                fclose(fpEmp);
                break;

            case Alumnos_except_empleados:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_ABRIR);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ABRIR);

                if ( retTotal == TODO_OK )
                {
                    ret= abrirArchivo(&fp_A_exp_E, ARCH_BIN_A_EXCEPT_E, "wb");
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_A_EXCEPT_E, MSJ_CREAR);

                    if ( retTotal == TODO_OK )
                    {
                        ret = excluir (fpAlum,sizeof(t_alumno), fpEmp, sizeof(t_empleado), fp_A_exp_E);
                        retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                        msj_de_retorno_proceso(ret, ARCH_BIN_A_EXCEPT_E, MSJ_EXCEPCION);
                    }

                    fclose(fp_A_exp_E);
                }

                fclose(fpAlum);
                fclose(fpEmp);
                break;

            case Empleados_except_alumnos:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_ALUM, MSJ_ABRIR);

                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret, ARCH_BIN_EMP, MSJ_ABRIR);

                if ( retTotal == TODO_OK )
                {
                    ret= abrirArchivo(&fp_E_exp_A, ARCH_BIN_E_EXCEPT_A, "wb");
                    retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                    msj_de_retorno_archivo(ret, ARCH_BIN_E_EXCEPT_A, MSJ_CREAR);

                    if ( retTotal == TODO_OK )
                    {
                        ret = excluir ( fpEmp,sizeof(t_empleado), fpAlum,sizeof(t_alumno), fp_E_exp_A);
                        retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                        msj_de_retorno_proceso(ret, ARCH_BIN_E_EXCEPT_A, MSJ_EXCEPCION);
                    }

                    fclose(fp_E_exp_A);
                }

                fclose(fpAlum);
                fclose(fpEmp);
                break;

            case Mostrar_archivos:

                ret= abrirArchivo(&fpAlum, ARCH_BIN_ALUM, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_ALUM , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de alumnos %s:\n\n", ARCH_BIN_ALUM);
                    mostrarArchivoAlumnos(fpAlum);
                    printf ("\n\n\n");
                }


                ret= abrirArchivo(&fpEmp, ARCH_BIN_EMP, "rb");
                retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_EMP , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de empleados %s:\n\n", ARCH_BIN_EMP);
                    mostrarArchivoEmpleados(fpEmp);
                    printf ("\n\n\n");
                }

                ret= abrirArchivo(&fpMerge, ARCH_BIN_MERGE, "rb");
                //retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_MERGE , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de Merge %s:\n\n", ARCH_BIN_MERGE);
                    mostrarArchivoEmpleados(fpMerge);
                    printf ("\n\n\n");
                }

                ret= abrirArchivo(&fpUnion, ARCH_BIN_A_UNION_E, "rb");
                //retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_A_UNION_E , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de Union %s:\n\n", ARCH_BIN_A_UNION_E);
                    mostrarArchivoPersona(fpUnion);
                    printf ("\n\n\n");
                }

                ret= abrirArchivo(&fpIntersection, ARCH_BIN_A_INTERSECTION_E, "rb");
                //retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_A_INTERSECTION_E , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de Interseccion %s:\n\n", ARCH_BIN_A_INTERSECTION_E);
                    mostrarArchivoPersona(fpIntersection);
                    printf ("\n\n\n");
                }

                ret= abrirArchivo(&fp_A_exp_E, ARCH_BIN_A_EXCEPT_E, "rb");
                //retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_A_EXCEPT_E , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de Excepcion %s:\n\n", ARCH_BIN_A_EXCEPT_E);
                    mostrarArchivoPersona(fp_A_exp_E);
                    printf ("\n\n\n");
                }

                ret= abrirArchivo(&fp_E_exp_A, ARCH_BIN_E_EXCEPT_A, "rb");
                //retTotal = ret == TODO_OK ? ret : ERROR_PROCESO ;
                msj_de_retorno_archivo(ret,ARCH_BIN_E_EXCEPT_A , MSJ_ABRIR  );
                if ( ret == TODO_OK)
                {
                    printf ("\n Archivo de Excepcion %s:\n\n", ARCH_BIN_E_EXCEPT_A);
                    mostrarArchivoPersona(fp_E_exp_A);
                    printf ("\n\n\n");
                }

                if (retTotal == TODO_OK)
                    printf ("\n Visualizacion de archivos correcta.\n");
                else
                    printf ("\n Ocurrio un error en la visualizacion de archivos.\n");

                fclose(fpAlum);
                fclose(fpEmp);
                fclose(fpMerge);
                fclose(fpUnion);
                fclose(fpIntersection);
                fclose(fp_A_exp_E);
                fclose(fp_E_exp_A);

                break;

            case Eliminar_archivos:
                remove(ARCH_BIN_ALUM);
                remove(ARCH_BIN_EMP);
                remove(ARCH_BIN_MERGE);
                remove(ARCH_BIN_A_UNION_E);
                remove(ARCH_BIN_A_INTERSECTION_E);
                remove(ARCH_BIN_A_EXCEPT_E);
                remove(ARCH_BIN_E_EXCEPT_A);
                printf ("\n Archivos eliminados:\n |%s|\n |%s|\n |%s|\n |%s|\n |%s|\n |%s|\n |%s|\n"
                        ,ARCH_BIN_ALUM
                        ,ARCH_BIN_EMP
                        ,ARCH_BIN_MERGE
                        ,ARCH_BIN_A_UNION_E
                        ,ARCH_BIN_A_INTERSECTION_E
                        ,ARCH_BIN_A_EXCEPT_E
                        ,ARCH_BIN_E_EXCEPT_A );

                break;

            case Reiniciar_Programa:
                main();
                return 0;
                break;
            default:
                printf ("\n Error inesperado.\n");
                break;
        }
        printf ("\n\n");
        system("pause");
        system("cls");
        opc = menu();
    }

    if (retTotal == TODO_OK)
        printf ("\n Finalizacion correcta\n\n");
    else
        printf ("\n Pasaron cosas\n\n");
    return 0;
}

void msj_de_retorno_archivo (const int ret, const char *nom, const char *msj)
{
    if ( ret != TODO_OK)
        fprintf(stderr, "\n %s %s\n", msj_error_archivo(ret), nom);
    else
        printf ("\n Archivo %s exitosamente: %s.\n", msj, nom);
}

void msj_de_retorno_proceso(const int ret, const char *nom, const char *msj)
{
    if ( ret != TODO_OK)
        fprintf(stderr, "\n Error durante el proceso de %s: %s\n", msj, nom);
    else
        printf ("\n Archivo %s exitosamente: %s.\n", msj, nom);
}

void ordenarLote(void *d,size_t ce, size_t tam, size_t tipoOrd, Cmp cmp)
{
    switch(tipoOrd)
    {
        case 0:
            ordenar_burbujeo(d,ce,tam,cmp);
            break;
        case 1:
            ordenar_seleccion(d, ce, tam,cmp);
            break;
        case 2:
            qsort(d, ce, tam,cmp);
            break;
        default:
            break;
    }
}

int mergear (FILE *fpAlum, FILE *fpEmp, FILE *fpMerge)
{
    t_alumno alum;
    t_empleado emp;
    /// Ya tenia una funcion de compara personas. Por eso creo estos punteros para
    /// no tener que volver a hacer una funcion de compara
    t_persona *p1=(t_persona *)&emp,
              *p2=(t_persona *)&alum;
    int cmp;

    if (!fpAlum || !fpEmp)
        return -1;

    rewind(fpAlum);
    rewind(fpEmp);

    fread(&emp, sizeof(t_empleado),1,fpEmp);
    fread(&alum, sizeof(t_alumno),1,fpAlum);


    while (!feof(fpAlum) && !feof(fpEmp) )
    {
        cmp = comparaPersonas(p1, p2);

        if (cmp == 0)
        {
            if (alum.notas[promedio] >= 7)
            {
                emp.sueldo *= 1.0728;
                str_cpy(emp.mensaje, "AUMENTO");
            }


            fwrite (&emp, sizeof(t_empleado),1, fpMerge);
            fread(&emp, sizeof(t_empleado),1,fpEmp);
            fread(&alum, sizeof(t_alumno),1, fpAlum);
        }

        if (cmp < 0)
        {
            fwrite (&emp, sizeof(t_empleado),1, fpMerge);
            fread(&emp, sizeof(t_empleado),1,fpEmp);
        }

        if (cmp > 0)
        {
            fread(&alum, sizeof(t_alumno),1, fpAlum);
        }
    }

    while (!feof(fpEmp))
    {
        fwrite (&emp, sizeof(t_empleado),1, fpMerge);
        fread(&emp, sizeof(t_empleado),1,fpEmp);
    }

    return TODO_OK;
}

int unir (FILE *fpAlum, FILE *fpEmp, FILE *fpUnion)
{
    t_alumno alum;
    t_empleado emp;

    t_persona *p1=(t_persona *)&emp,
              *p2=(t_persona *)&alum;
    int cmp;

    if (!fpAlum || !fpEmp)
        return -1;

    rewind(fpAlum);
    rewind(fpEmp);

    fread(&emp, sizeof(t_empleado),1,fpEmp);
    fread(&alum, sizeof(t_alumno),1,fpAlum);


    while (!feof(fpAlum) && !feof(fpEmp) )
    {
        cmp = comparaPersonas(p1, p2);

        if (cmp == 0)
        {
            fwrite (p1, sizeof(t_persona),1, fpUnion);
            fread(&emp, sizeof(t_empleado),1,fpEmp);
            fread(&alum, sizeof(t_alumno),1, fpAlum);
        }

        if (cmp < 0)
        {
            fwrite (p1, sizeof(t_persona),1, fpUnion);
            fread(&emp, sizeof(t_empleado),1,fpEmp);
        }


        if (cmp > 0)
        {
            fwrite (p2, sizeof(t_persona),1, fpUnion);
            fread(&alum, sizeof(t_alumno),1, fpAlum);
        }

    }

    while (!feof(fpEmp))
    {
        fwrite (p1, sizeof(t_persona),1, fpUnion);
        fread(&emp, sizeof(t_empleado),1,fpEmp);
    }

    while (!feof(fpAlum))
    {
        fwrite (p2, sizeof(t_persona),1, fpUnion);
        fread(&emp, sizeof(t_alumno),1,fpAlum);
    }


    return TODO_OK;
}

int interseccion (FILE *fpAlum, FILE *fpEmp, FILE *fpIntersection)
{
    t_alumno alum;
    t_empleado emp;

    t_persona *p1=(t_persona *)&emp,
              *p2=(t_persona *)&alum;
    int cmp;

    if (!fpAlum || !fpEmp)
        return -1;

    rewind(fpAlum);
    rewind(fpEmp);

    fread(&emp, sizeof(t_empleado),1,fpEmp);
    fread(&alum, sizeof(t_alumno),1,fpAlum);


    while (!feof(fpAlum) && !feof(fpEmp) )
    {
        cmp = comparaPersonas(p1, p2);

        if (cmp == 0)
        {
            fwrite (p1, sizeof(t_persona),1, fpIntersection);
            fread(&emp, sizeof(t_empleado),1,fpEmp);
            fread(&alum, sizeof(t_alumno),1, fpAlum);
        }

        if (cmp < 0)
            fread(&emp, sizeof(t_empleado),1,fpEmp);

        if (cmp > 0)
            fread(&alum, sizeof(t_alumno),1, fpAlum);

    }

    return TODO_OK;
}

int excluir (FILE *fpX, size_t tamX, FILE *fpY, size_t tamY, FILE *fpExcep)
{
    void *p1=malloc (tamX),
         *p2=malloc (tamY);

    int cmp;

    if (!p1 || !p2)
        return -1;

    if (!fpX || !fpY)
        return -1;

    rewind(fpX);
    rewind(fpY);

    fread(p1, tamX,1,fpX);
    fread(p2, tamY,1,fpY);


    while (!feof(fpX) && !feof(fpY) )
    {
        cmp = comparaPersonas(p1, p2);

        if (cmp == 0)
        {
            fread(p1, tamX,1,fpX);
            fread(p2, tamY,1, fpY);
        }

        if (cmp < 0)
        {
            fwrite(p1, sizeof(t_persona),1, fpExcep);
            fread(p1, tamX,1,fpX);
        }


        if (cmp > 0)
            fread(p2, tamY,1, fpY);

    }

    while(!feof(fpX))
    {
        fwrite(p1, tamX,1, fpExcep);
        fread(p1, tamX,1,fpX);
    }

    return TODO_OK;
}

void mostrarArchivoPersona(FILE *fp)
{

    t_persona per;
    int i=0;

    rewind(fp);
    fread(&per,sizeof(t_persona),1,fp);

    while (!feof(fp))
    {
        mostrarPersonas(&per,++i);
        fread(&per,sizeof(t_persona),1,fp);
    }
}

void mostrarArchivoAlumnos(FILE *fpAlum)
{
    t_alumno alum;
    int i=0;

    rewind(fpAlum);
    fread(&alum,sizeof(t_alumno),1,fpAlum);

    while (!feof(fpAlum))
    {
        mostrarAlumnos(&alum,++i);
        fread(&alum,sizeof(t_alumno),1,fpAlum);
    }
}

void mostrarArchivoEmpleados(FILE *fpEmp)
{
    t_empleado emp;
    int i=0;

    rewind(fpEmp);
    fread(&emp,sizeof(t_empleado),1,fpEmp);

    while (!feof(fpEmp))
    {
        mostrarEmpleados(&emp,++i);
        fread(&emp,sizeof(t_empleado),1,fpEmp);
    }
}
