#include <stddef.h>
#include <stdio.h>

#include "Archivo.h"
#include "Linea.h"
#include "define.h"

struct nodoArchivo{
  char *nombreArchivo;
  linea cont;
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
      a->sig = insert_Archivo(a->sig, nArchivo, tamanio);
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
  else if (a->nombreArchivo != nombreArchivo)
    return buscaArchivo (a->sig, nombreArchivo);
  else
    return a;
}

//---------------------------------------------------------------------

archivo insertaEnArchivo (archivo a, char *nombreArchivo, char *texto){
  archivo arAUX = buscaArchivo (a, nombreArchivo);//cambie los arAUX = a por busca archivo
  linea lnAUX = arAUX->cont;
  if (cantLineas(lnAUX) < arAUX->max)
    insertaLinea (lnAUX, nombreArchivo, texto);
  else
    printf("Error: El texto es mayor al soportado por el archivo");
  return a;
}

//---------------------------------------------------------------------

archivo eliminar_Archivo(archivo a, char *nombreArchivo){
    if(a == NULL)
      return a;
    else if(strcmp(a->nombreArchivo, nombreArchivo) == 0){
      archivo arAUX = eliminar_Archivo(a->sig, nombreArchivo);
      borrarLineas (arAUX->cont, arAUX->max);
      delete a;
      return arAUX;
    }
    else{
      a->sig = eliminar_Archivo(a->sig, nombreArchivo);
      return a;
    }
    return a;///
}

//---------------------------------------------------------------------

archivo eliminar_CantLineas (archivo a, char *nombreArchivo, int k){

  archivo arAUX = buscaArchivo (a, nombreArchivo);//cambie los arAUX = a por busca archivo
  borrarLineas (arAUX->cont, k);
  printf("lineas borradas");
  return a;
}

//---------------------------------------------------------------------

archivo Concat(archivo a, char *nombreArchivo1, char *nombreArchivo2){
  archivo arAUX = a;
  archivo arAUX1 = buscaArchivo (arAUX, nombreArchivo1);//busca y asigna el asrchivo a cada variable
  archivo arAUX2 = buscaArchivo (arAUX, nombreArchivo2);
  if (arAUX1 == NULL){
    printf("el archivo 1 no existe");
    return a;
  }
  if (arAUX2 == NULL){
    printf("el archivo 2 no existe");
    return a;
  }
  while (arAUX2->cont != NULL){
    insertaEnArchivo (arAUX1, nombreArchivo1, devuelveContenidodeLinea(arAUX2->cont));//hace un control innecesario despues (busca archivo denuevo), pero creo q no pasa nada
    arAUX2->cont = avanzaEnLineas(arAUX->cont);//la idea es q avance el puntero en el contenido para mostrar el char q sigue en la lisa y asi ir metiendolos de a uno
  }//el devuelve contenido de linea es porq necesito poner un char para reutilizar la funcion de inserta en archivo
return a;/// para que compile
}
