#include <string.h>
#include <stdio.h>
#include <iostream>
#include "gestor.h"

struct nodo_directorio{
  char *nombre;
  archivo a;
};

struct nodo_sistema{
  directorio d;
};

struct nodo_archivo{
  char *nombre;
  char *texto;
  int tamanio;
  archivo sig;
};

sistema createSistema(){
	return NULL;
}

TipoRet createRaiz(sistema &s){
  //if (s == NULL){
    directorio dirAUX = new (nodo_directorio);
    dirAUX->nombre = new char[strlen("/") + 1];
    strcpy(dirAUX->nombre, "/");
    dirAUX->a = NULL;
    s = new (nodo_sistema);
    s->d = dirAUX;
    return OK;
  //}
  //else{
    //return ERROR;
  //}
}

TipoRet createArchivo (sistema &s, char *nombreArchivo){
  if (buscaNombre(s->d->a, nombreArchivo)){
      if(s->d->a == NULL){
        archivo aux = new (nodo_archivo);
        strcpy(aux -> nombre, nombreArchivo);
        aux -> sig = NULL;
        return OK;
      }

      else{
      archivo aux = s->d->a;
      while (aux->sig != NULL){
        aux = aux->sig;
      }
      archivo aux2 = new (nodo_archivo);
      strcpy(aux2 -> nombre, nombreArchivo);
      aux -> sig = aux2;
      delete aux;
      return OK;
      }
  }
  else
    return ERROR;
}

bool buscaNombre (archivo a, char *nombre){
  if (a == NULL)
    return true;
  else if (strcmp(a->nombre, nombre) != 0)
    return buscaNombre(a->sig,nombre);
  else {
    return false;
  }
}
TipoRet DELETE (sistema &s, char *nombreArchivo){
  return NO_IMPLEMENTADA;
}

TipoRet DIR (sistema &s , char *parametro){
  return NO_IMPLEMENTADA;
}

TipoRet IC (sistema &s, char *nombreArchivo, char *texto){
  return NO_IMPLEMENTADA;
}

TipoRet IF (sistema &s, char *nombreArchivo, char *texto){
  return NO_IMPLEMENTADA;
}

TipoRet TYPE (sistema &s, char *nombreArchivo){
  return NO_IMPLEMENTADA;
}

TipoRet BF (sistema &s, char *nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}

TipoRet BC (sistema &s, char *nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}
