#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"
#include "Archivo.h"


typedef struct nodoDirectorio * directorio;

directorio insert_Directorio(directorio d, char *nDirectorio);

directorio create_Raiz(directorio d);

bool createDirectorio (directorio & d, char * path);

directorio busca_directorio(directorio d, char *parametro);

void print_Directorio(directorio d);

directorio CreateArchivoDirectorio(directorio d, char *nombreArchivo, int tamanio);

directorio IFDirectorio(directorio d, char *nombreArchivo, char *texto);

directorio TYPEDirectorio(directorio d,char *nombreArchivo);

directorio DELETEArchivoDirectorio(directorio d, char *nombreArchivo);

directorio BFDirectorio(directorio d, char *nombreArchivo, int k);

directorio CATDirectorio(directorio d, char *nombreArchivo1, char *nombreArchivo2);

char* get_nDirectorio(directorio d); //retorna el nombre del directorio

bool DIRpertenece (directorio d, char * nombreDir);

directorio CDdir (directorio d, char*nombreDir);

void PWDir (directorio d, char * nombreDirectorio);

#endif
