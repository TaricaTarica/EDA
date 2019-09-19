#ifndef GESTOR_H
#define GESTOR_H

typedef struct nodo_sistema * sistema;
typedef struct nodo_archivo * archivo;
typedef struct nodo_directorio * directorio;
enum retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum retorno TipoRet;



sistema createSistema ();
//crea sistema vacío

TipoRet createRaiz(sistema &s);
//crea la carpeta raíz en el sistema

TipoRet createArchivo (sistema &s, char *nombreArchivo);
//crea un nuevo archivo vacío en el directorio especificado por su ruta
//pre: sistema y directorio no son NULL.

TipoRet DELETE (sistema &s, char *nombreArchivo);
//elimina un archivo del Sistema de Archivos

TipoRet DIR (sistema &s , char *parametro);
//muestra el contenido del directorio actual, ya sean subdirectorios o archivos

TipoRet IC (sistema &s, char *nombreArchivo, char *texto);
//Inserta una línea al comienzo del texto del archivo NombreArchivo
//la información a insertardebe ir entre comillas (“), el texto a su vez no podrá contener ese caracter

TipoRet IF (sistema &s, char *nombreArchivo, char *texto);
//Inserta una línea al final del texto del archivo NombreArchivo

TipoRet TYPE (sistema &s, char *nombreArchivo);
//Muestra por pantalla el contenido del archivo NombreArchivo

TipoRet BF (sistema &s, char *nombreArchivo, int k);
//Borra, a lo sumo, las k últimas líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

TipoRet BC (sistema &s, char *nombreArchivo, int k);
//Borra, a lo sumo, las k primeras líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

bool buscaNombre (archivo a, char *nombre);
//busca si el nombre del directorio o archivo esta en uso en esa instancia.


#endif
