#include "gestor.h"
#include <string.h>
#include <stdio.h>
#include <iostream>


struct nodo_sistema{
  directorio d;
};

struct nodo_directorio{
  string nombre;
  archivo a;
};

struct nodo_archivo{
  string nombre;
  string texto;
  int tamanio;
  archivo sig;
};

enum retorno{
  OK, ERROR, NO_IMPLEMENTADA
};

sistema createSistema(){
	return NULL;
}

TipoRet createRaiz(sistema &s){
  if (s == NULL){
    s = new (nodo_sistema);
    s->d = new (nodo_directorio);
    s->d->nombre = "/"
    s->d->archivo = NULL;
    return OK;
  }
  else{
    return ERROR;
  }
}

TipoRet createArchivo (Sistema &s, string nombreArchivo){
  if (buscaNombre(s->d->a, nombreArchivo)){
      if(s->d->a == NULL){
        archivo aux = new (nodo_archivo);
        aux -> nombre = nombreArchivo;
        aux -> sig = NULL;
        return OK;
      }

      else{
      archivo aux = s->d->a;
      while (aux->sig != NULL){
        aux = aux->sig;
      }
      aux2 = new (nodo_archivo);
      aux2 -> nombre = nombreArchivo;
      aux -> sig = aux2;
      delete aux;
      return OK;
      }
  }
  else
    return ERROR;
}

bool buscaNombre (archivo a, string nombre){
  if (s == NULL)
    return true;
  else if (a->nombre != nombre)
    return buscaNombre(a->sig,nombre);
  else {
    return false;
  }
}
TipoRet delete (sistema &s, string nombreArchivo){
  return NO_IMPLEMENTADA;
}

TipoRet dir (sistema &s , string parametro){
  return NO_IMPLEMENTADA;
}

TipoRet ic (sistema &s, string nombreArchivo, string texto){
  return NO_IMPLEMENTADA;
}

TipoRet if (sistema &s, string nombreArchivo, string texto){
  return NO_IMPLEMENTADA;
}

TipoRet type (sistema &s, string nombreArchivo){
  return NO_IMPLEMENTADA;
}

TipoRet bf (sistema &s, string nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}

TipoRet bc (sistema &s, string nombreArchivo, int k){
  return NO_IMPLEMENTADA;
}

bool buscaNombre (sistema s, string nombre){
  return NO_IMPLEMENTADA;
}
