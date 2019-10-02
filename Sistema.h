#ifndef SISTEMA_H
#define SISTEMA_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

typedef struct nodoSistema * Sistema;

TipoRet DIR (Sistema &s);
//Este comando muestra el contenido del directorio actual, ya sean subdirectorios o archivos.
TipoRet CREATE (Sistema &s, char *nombreArchivo);
//Este comando crea un nuevo archivo vacío en el directorio especificado por su ruta (ya sea relativa o absoluta)
TipoRet DELETE (Sistema &s, char *nombreArchivo);
//Este comando elimina un archivo del Sistema de Archivos. El archivo a ser borrado puede ser especificado mediante una ruta relativa o absoluta.
TipoRet UNDELETE (Sistema &s);
//Este comando recupera el último archivo eliminado en el sistema mediante el comando DELETE (si hay al menos uno, sino no tiene efecto), restaurándolo al directorio en donde fue eliminado, siempre y cuando este directorio, determinado por su ruta, exista.


#endif
