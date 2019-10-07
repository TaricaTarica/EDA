#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"
#include "Linea.h"

typedef struct nodoArchivo * archivo;


archivo insert_Archivo(archivo a, char *nArchivo, int tamanio);

void print_Archivo(archivo a);

archivo buscaArchivo (archivo a, char *nombreArchivo);

archivo insertaEnArchivo (archivo a, char *nombreArchivo, char *texto);

archivo eliminar_Archivo(archivo a, char *nombreArchivo);

#endif
