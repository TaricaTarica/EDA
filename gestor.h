#ifndef GESTOR_H
#define GESTOR_H

typedef struct nodo_sistema * sistema;
typedef struct nodo_archivo * archivo;
typedef struct nodo_directorio * directorio;
typedef enum retorno TipoRet;



sistema createSistema ();
//crea sistema vacío

TipoRet createRaiz(sistema &s);
//crea la carpeta raíz en el sistema

TipoRet createArchivo (sistema &s, string nombreArchivo);
//crea un nuevo archivo vacío en el directorio especificado por su ruta
//pre: sistema y directorio no son NULL.

TipoRet delete (sistema &s, string nombreArchivo);
//elimina un archivo del Sistema de Archivos

TipoRet dir (sistema &s , string parametro);
//muestra el contenido del directorio actual, ya sean subdirectorios o archivos

TipoRet ic (sistema &s, string nombreArchivo, string texto);
//Inserta una línea al comienzo del texto del archivo NombreArchivo
//la información a insertardebe ir entre comillas (“), el texto a su vez no podrá contener ese caracter

TipoRet if (sistema &s, string nombreArchivo, string texto);
//Inserta una línea al final del texto del archivo NombreArchivo

TipoRet type (sistema &s, string nombreArchivo);
//Muestra por pantalla el contenido del archivo NombreArchivo

TipoRet bf (sistema &s, string nombreArchivo, int k);
//Borra, a lo sumo, las k últimas líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

TipoRet bc (sistema &s, string nombreArchivo, int k);
//Borra, a lo sumo, las k primeras líneas de texto del archivo NombreArchivo.
//Si el texto tiene k o menos líneas, éste queda vacío.

bool buscaNombre (sistema s, string nombre);
//busca si el nombre del directorio o archivo esta en uso en esa instancia.


#endif
