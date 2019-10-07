#include <stddef.h>
#include <stdio.h>

#include "Archivo.h"
#include "define.h"
#include "Linea.h"

struct nodoarchivo{
  string n;
  lineas cont;
  int max;
  archivo sig;
};

archivo insert_Archivo(archivo a, char *nArchivo, int tamanio){
    if(a == NULL){
      archivo aux = new(nodoArchivo);
      aux->nombreArchivo = new char[strlen(nArchivo) + 1];
      strcpy(aux->nombreArchivo, nArchivo);
      aux->cont = NULL;
      aux->max = tamanio;
      aux->sig = NULL;

      return aux;
    }
    else{
      a->sig = insert_Archivo(a->sig, nArchivo);
      return a;
    }
}

//---------------------------------------------------------------------

void print_Archivo(archivo a){
  if(a != NULL){
    archivo aux = a;
    while(aux->sig != NULL){
      printf("- %s", aux->nombreArchivo);
      printf("\n");
      aux = aux->sig;
    }
  }
}

//---------------------------------------------------------------------

archivo buscaArchivo (archivo a, char *nombreArchivo){
  if (a==NULL)
    return NULL;
  if (a->nombre != nombre)
    buscaArchivo (a->sig, nombreArchivo, texto);
  else
    return a;
  }
}

//---------------------------------------------------------------------

archivo insertaEnArchivo (archivo a, char *nombreArchivo, char *texto){
  archivo arAUX = a;
  lineas lnAUX = arAUX->cont;
  if (cantLineas(lnAUX) < max)
    insertaLinea (lnAUX, nombreArchivo, texto);
  return a;
}
