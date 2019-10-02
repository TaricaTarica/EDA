#include <stddef.h>
#include <stdio.h>

#include "Directorio.h"
#include "Archivo.h"
#include "define.h"


struct nodoDirectorio{
    char *nombreDirectorio;
    archivo a;
    nodoDirectorio *sig;
};

directorio create_Raiz(directorio d){
  if(d != NULL){
    directorio aux = new(nodoDirectorio);
    aux->nombreDirectorio = new char[strlen("/") + 1];
    strcpy(aux->nombreDirectorio, "/");
    aux->a = NULL;
    aux->sig = NULL;
    return aux;
  }
  else
    return d;
}


directorio insert_Directorio(directorio d, char *nDirectorio){
    if(d == NULL){
    directorio aux = new(nodoDirectorio);
    aux->nombreDirectorio = new char[strlen(nDirectorio) + 1];
    strcpy(aux->nombreDirectorio, nDirectorio);
    aux->a = NULL;
    aux->sig = NULL;
    return aux;
    }
    else{
        d->sig = insert_Directorio(d->sig, nDirectorio);
        return d;
    }
}

void print_Directorio(directorio d){
  directorio dirAUX = d;
  archivo arAUX = dirAUX->a;
  while(dirAUX->sig != NULL){
    printf("+ %s", dirAUX->nombreDirectorio);
    if(arAUX != NULL){
      printf("\n");
      printf("\t \t \t \t");
      print_Archivo(arAUX);
    }
    printf("\n");
    dirAUX = dirAUX->sig;
  }

}
