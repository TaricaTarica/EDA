#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

typedef struct nodoArchivo * archivo;

archivo insert_Archivo(archivo a, char *nArchivo, int tamanio);
//crea el archivo a insertar en el Directorio

void print_Archivo(archivo a);
//imprme el nombre de todos los archivos

archivo buscaArchivo (archivo a, char *nombreArchivo);
//busca si existe el archivo con nombre nombreArchivo

archivo insertaEnArchivo (archivo a, char *texto);
//inserta una linea en archivo nombreArchivo

archivo eliminar_Archivo(archivo a, char *nombreArchivo);
//elimina las lineas del archivo nombreArchivo y luego el archivo mismo

archivo eliminar_CantLineas (archivo a, char *nombreArchivo, int k);
//elimina cierta cantidad de lineas del archivo nombreArchivo

archivo Concat(archivo a, char *nombreArchivo1, char *nombreArchivo2);
//inserta las lineas de nombreArchivo2 al final de nombreArchivo1, o eso intenté

archivo IFArchivo (archivo a,char *nombreArchivo, char *texto);

archivo TYPEArchivo(archivo a, char *nombreArchivo);


#endif
