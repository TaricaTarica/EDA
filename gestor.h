#ifndef GESTOR_H
#define GESTOR_H

typedef struct nodo_directorio * directorio;
typedef struct nodo_sistema * sistema;
typedef struct nodo_archivo * archivo;
enum retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum retorno TipoRet;



sistema CREATESISTEMA();
//crea sistema vacío

TipoRet CREATERAIZ(sistema &s);
//crea la carpeta raíz en el sistema

TipoRet CREATEARCHIVO (sistema &s, char *nombreArchivo);
//crea un nuevo archivo vacío en el directorio especificado por su ruta
//pre: sistema y directorio no son NULL.

TipoRet IF (sistema &s, char *nombreArchivo, char *texto);
//Inserta una línea al final del texto del archivo NombreArchivo

TipoRet TYPE (sistema &s, char *nombreArchivo);
//Muestra por pantalla el contenido del archivo NombreArchivo

TipoRet DIR (sistema &s , char *parametro);
//muestra el contenido del directorio actual, ya sean subdirectorios o archivos

//------------------------------------------------------------------------ TIPO2

TipoRet DELETE (sistema &s, char *nombreArchivo);
//elimina un archivo del Sistema de Archivos
//PRE: Hay archivos creados

TipoRet BF (sistema &s, char *nombreArchivo, int k);
//Borra, a lo sumo, las k últimas líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

//------------------------------------------------------------------------ TIPO3

TipoRet IC (sistema &s, char *nombreArchivo, char *texto);
//Inserta una línea al comienzo del texto del archivo NombreArchivo
//la información a insertardebe ir entre comillas (“), el texto a su vez no podrá contener ese caracter

TipoRet BC (sistema &s, char *nombreArchivo, int k);
//Borra, a lo sumo, las k primeras líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

//------------------------AUXILIARES--------------------------------------------

bool buscaNombre (archivo a, char *nombre);
//busca si el nombre del directorio o archivo esta en uso en esa instancia.

archivo buscaArchivo (archivo a, char *nombre);
//Devuelve el archivo buscado
//PRE: Ejecutar buscaNombre

#endif
