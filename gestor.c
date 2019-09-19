#include "gestor.h"
#include <string.h>
#include <stdio.h>
#include <iostream>


struct nodo_sistema{
  directorio d;
};

struct nodo_directorio{
  char *nombre;
  archivo a;
};

struct nodo_archivo{
  char *nombre;
  char *texto;
  int tamanio;
  archivo sig;
};



sistema CREATESISTEMA(){
	return NULL;
}

TipoRet CREATERAIZ(sistema &s){
  if (s == NULL){
    s = new (nodo_sistema);
    s->d = new (nodo_directorio);
    strcpy(s->d->nombre, "/");
    s->d->a = NULL;
    return OK;
  }
  else{
    return ERROR;
  }
}

//---------------------------------------TIPO 1 (IMPRESCINDIBLES)

TipoRet CREATEARCHIVO (sistema &s, char *nombreArchivo){
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


TipoRet IF (sistema &s, char *nombreArchivo, char *texto){
  return NO_IMPLEMENTADA;
}

	
TipoRet TYPE (sistema &s, char *nombreArchivo){
  return NO_IMPLEMENTADA;
}

//---------------------------------------TIPO 2
TipoRet DELETE (sistema &s, char *nombreArchivo){
  return NO_IMPLEMENTADA;
}

TipoRet BF (sistema &s, char *nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}

TipoRet CAT (Sistema &s, string nombreArchivo1, char *nombreArchivo2){
  return NO_IMPLEMENTADA;
}

TipoRet DIR (sistema &s , char *parametro){
  return NO_IMPLEMENTADA;
}

//--------------------------------------TIPO 3

TipoRet IC (sistema &s, char *nombreArchivo, char *texto){
  return NO_IMPLEMENTADA;
}

TipoRet BC (sistema &s, char *nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}
