#include "archivo.h"

size_t abrirArchivo(FILE **fp, const char *nom, const char *modo)
{
    *fp = fopen(nom,modo);

    if (!*fp)
        return ERR_ARCH_1;

    return TODO_OK;
}

size_t grabarInfoEnBin (FILE *fp, const void *dato, const size_t tam, const size_t cantReg)
{
    return fwrite(dato, tam, cantReg, fp) == cantReg ? TODO_OK : ERR_ARCH_2;
}

size_t leerInfoEnBin (FILE *fp, void *dato, const size_t tam, const size_t cantReg)
{
    return fread(dato, tam, 1, fp) == cantReg ? TODO_OK : ERR_ARCH_3;
}

const char * msj_error_archivo (const size_t numErr)
{
    switch(numErr)
    {
        case ERR_ARCH_1:
            return ("Error de apertura de archivo." );
            break;
        case ERR_ARCH_2:
            return "Error de escritura de archivo.";
            break;
        case ERR_ARCH_3:
            return "Error de lectura de archivo.";
            break;
        default:
            return "Error inesperado de archivo.";
            break;
    }
}

