#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stddef.h>
#include "define.h"
#include "Linea.h"



struct nodo_linea{
    char *l;
    linea sig;
};


linea insertaLinea (linea ln, char *texto){
  if (ln == NULL){
    linea aux = new(nodo_linea);
    aux->l = new char[strlen(texto) + 1];
    strcpy(aux->l, texto);
    aux->sig = NULL;
    return aux;
  }
  else{
    ln->sig = insertaLinea (ln->sig, texto);
    return ln;
  }
}

//---------------------------------------------------------------------

int cantLineas (linea ln){
  if (ln == NULL)
    return 0;
  else
    return 1 + cantLineas(ln->sig);
}

//---------------------------------------------------------------------

void imprimirLineas (linea ln){
  if(ln != NULL){
    linea aux = ln;
    while(aux->sig != NULL){
      printf(" %s ", aux->l);
      aux = aux->sig;
    }
  }
}

//---------------------------------------------------------------------

void borrarLineas (linea ln, int cant){
  if(ln != NULL)
    borrarLineas (ln->sig, cant);
  ln->l = NULL;
  ln->sig = NULL;
  delete ln;
}

//---------------------------------------------------------------------

linea avanzaEnLineas (linea ln){
  return ln->sig;
}
//---------------------------------------------------------------------
char* devuelveContenidodeLinea (linea ln){
  return ln->l;
}
//---------------------------------------------------------------------
linea IFLinea (linea ln, char *texto, int max){
  while (cantLineas(ln)< max){
    ln = insertaLinea (ln, texto);
    ln = ln->sig;
  }
  return ln;
}
