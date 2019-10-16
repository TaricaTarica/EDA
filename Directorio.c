#include <stddef.h>
#include <stdio.h>

#include "Directorio.h"
#include "Archivo.h"
#include "define.h"


struct nodoDirectorio{
    char *nombreDirectorio;
    archivo a;
    directorio sig;
};

directorio create_Raiz(directorio d){
  if(d == NULL){
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

//---------------------------------------------------------------------

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

//---------------------------------------------------------------------

void print_Directorio(directorio d){
  do{
    printf("+ %s", d->nombreDirectorio);
    printf("\n");
    printf("\t \t \t \t");
    print_Archivo(d->a);
    d = d->sig;
  }while (d->sig != NULL);
  printf("\n");
}


//---------------------------------------------------------------------

directorio CreateArchivoDirectorio(directorio d, char *nombreArchivo, int tamanio){
  if(d != NULL){
    d->a = insert_Archivo(d->a, nombreArchivo, tamanio);
    return d;
  }
  else
    return d;
}
//---------------------------------------------------------------------

directorio IFDirectorio(directorio d, char *nombreArchivo, char *texto){
  d->a = IFArchivo(d->a, nombreArchivo, texto);
  return d;

}

//---------------------------------------------------------------------

directorio TYPEDirectorio(directorio d,char *nombreArchivo){
  d->a = TYPEArchivo(d->a, nombreArchivo);
  return d;
}

//---------------------------------------------------------------------

directorio DELETEArchivoDirectorio(directorio d, char *nombreArchivo){
  d->a = eliminar_Archivo(d->a, nombreArchivo);
  return d;
}

//---------------------------------------------------------------------

directorio BFDirectorio(directorio d, char *nombreArchivo, int k){

  d->a = eliminar_CantLineas (d->a, nombreArchivo, k);
  return d;
}

//---------------------------------------------------------------------
directorio CATDirectorio(directorio d, char *nombreArchivo1, char *nombreArchivo2){
  d->a = Concat(d->a, nombreArchivo1, nombreArchivo2);
  return d;
}
