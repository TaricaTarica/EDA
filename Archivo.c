#include <stddef.h>
#include <stdio.h>

#include "Archivo.h"
#include "define.h"

struct nodoArchivo{
    char *nombreArchivo;
    nodoArchivo *sig;
};




archivo insert_Archivo(archivo a, char *nArchivo){
    if(a == NULL){
    archivo aux = new(nodoArchivo);
    aux->nombreArchivo = new char[strlen(nArchivo) + 1];
    strcpy(aux->nombreArchivo, nArchivo);
    aux->sig = NULL;
    return aux;
    }
    else{
        a->sig = insert_Archivo(a->sig, nArchivo);
        return a;
    }
}
void print_Archivo(archivo a){
  archivo aux = a;
  while(aux->sig != NULL){
    printf("- %s", aux->nombreArchivo);
    printf("\n");
    aux = aux->sig;
  }


}
