#ifndef SISTEMA_H
#define SISTEMA_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

typedef struct nodoSistema * Sistema;


Sistema create_Sistema();
//crea un sistema vacío.

TipoRet DIR (Sistema &s);
//Este comando muestra el contenido del directorio actual, ya sean subdirectorios o archivos.

TipoRet MKDIR (Sistema &s, char *cadena);
//Este comando creaun nuevo directorio en la rutaespecificada. Esta ruta puede ser tanto relativacomo absoluta.

TipoRet CREATE (Sistema &s, char *nombreArchivo, int tamanio);
//Este comando crea un nuevo archivo vacío en el directorio especificado por su ruta (ya sea relativa o absoluta)

TipoRet IF (Sistema &s, char *nombreArchivo, char *texto);
//Inserta una línea al final del texto del archivo NombreArchivo

TipoRet TYPE (Sistema &s, char *nombreArchivo);
//Muestra por pantalla el contenido del archivo NombreArchivo

TipoRet DELETE (Sistema &s, char *nombreArchivo);
//Este comando elimina un archivo del Sistema de Archivos. El archivo a ser borrado puede ser especificado mediante una ruta relativa o absoluta.

TipoRet BF (Sistema &s, char *nombreArchivo, int k);
//Borra, a lo sumo, las k últimas líneas de texto del archivo NombreArchivo. Si el texto tiene k o
//menos líneas, éste queda vacío.

TipoRet CAT (Sistema &s, char *nombreArchivo1, char *nombreArchivo2);
//Concatena el archivo de nombre NombreArchivo2 a continuación del archivo de nombre
//NombreArchivo1, dejando el contenido del archivo resultante en el archivo NombreArchivo1

TipoRet UNDELETE (Sistema &s);
//Este comando recupera el último archivo eliminado en el sistema mediante el comando DELETE
//(si hay al menos uno, sino no tiene efecto)
//restaurándolo al directorio en donde fue eliminado, siempre y cuando este directorio, determinado por su ruta, exista.

TipoRet CD (Sistema &s, char* nombreDirectorio);
//Este comando es el únicoque permite desplazarnos en la estructura de directorios, definiendo así al nuevo directorio actual.

TipoRet CDpadre (Sistema &s);
//mueve el diractual hacia el padre

TipoRet PWD (Sistema &s);
//Este   comando   muestra   el   camino   desde   la RAIZal directorioactual siguiendo   el   formato: “/.../.../dirActual”.

TipoRet RMDIR (Sistema &s, char* nombreDirectorio);
//Este comando eliminaundirectorioespecificado por una ruta(relativa o absoluta) además de todos los subdirectoriosy archivosque éste contenga

TipoRet COPY(Sistema &s, char* archidirOrigen, char* directorioDestino);
//Este  comando copia  un  directorio  o  archivo desde  un directorioorigen  hacia  un directoriodestino.
//Tanto el directorio origen como el directorio destino pueden estar especificados por sus rutasya sean relativas o absolutas.
//Como  es  de  suponerse,  al  copiar  un directorio,su  estructura  de subdirectorios debería quedar inalterada.

#endif
