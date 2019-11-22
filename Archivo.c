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
  if ( a != NULL && existeArchivo (a, nArchivo) == true){
    printf("el archivo ya existe");
    return a;
  }
  else{
    if(a == NULL){
      archivo aux = new(nodoArchivo);
      aux->nombreArchivo = new char[strlen(nArchivo) + 1];
      strcpy(aux->nombreArchivo, nArchivo);
      aux->cont = sangria();
      aux->max = tamanio;
      aux->sig = NULL;
      return aux;
    }
    else{
      a->sig = insert_Archivo(a->sig, nArchivo, tamanio);
      return a;
    }
  }
}

//---------------------------------------------------------------------

void print_Archivo(archivo a, int cont){
  archivo aux = a;
  if(aux != NULL){
    for (int auxcont = cont  ; auxcont > 0 ; auxcont --){
      if (auxcont > 1){
        printf ("\t");
      }
      else{
        printf("└───────");
      }
    }
    printf("+ %s", aux->nombreArchivo);
    printf("\n");
    if (aux->sig != NULL){
      aux = aux->sig;
      print_Archivo(aux, cont);
    }
  }
}

//---------------------------------------------------------------------

archivo buscaArchivo (archivo a, char *nombreArchivo){
  if (a==NULL){
    printf("no se encontró un archivo con ese nombre");
    return NULL;
  }
  else if (strcmp(a->nombreArchivo, nombreArchivo) != 0)
    return buscaArchivo (a->sig, nombreArchivo);
  else{
    return a;
  }
}

//---------------------------------------------------------------------

archivo insertaEnArchivo (archivo a,char *texto){
   a->cont = IFLinea(a->cont, texto, a->max);
   return a;
}

//---------------------------------------------------------------------

archivo eliminar_Archivo(archivo a, char *nombreArchivo){
  printf("1");
  if(a == NULL){
    return a;
  }
  else if(strcmp(a->nombreArchivo, nombreArchivo) == 0){
      printf("2");
      archivo aux = a;
      a = a->sig;
      borrarLineas(aux->cont, aux->max);
      delete aux;
      return a;
  }
  else if(strcmp(a->sig->nombreArchivo, nombreArchivo) == 0){
    printf("3");
    archivo aux = a->sig;
    a->sig = aux->sig;
    borrarLineas (aux->cont, aux->max);
    delete aux;
    return a;
  }
  else{
    a->sig = eliminar_Archivo(a->sig, nombreArchivo);
    return a;
  }
  return a;
}

//---------------------------------------------------------------------

archivo BFarchivo (archivo a, char *nombreArchivo, int k){
  a = buscaArchivo(a, nombreArchivo);
  if (a!=NULL){
    while (a->cont != NULL && k>0){
      a->cont = BFlineas (a->cont);
      k--;
    }
  }
  return a;
}

//---------------------------------------------------------------------

/*archivo Concat(archivo a, char *nombreArchivo1, char *nombreArchivo2){
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
    insertaEnArchivo (arAUX1, devuelveContenidodeLinea(arAUX2->cont));//hace un control innecesario despues (busca archivo denuevo), pero creo q no pasa nada
    arAUX2->cont = avanzaEnLineas(arAUX->cont);//la idea es q avance el puntero en el contenido para mostrar el char q sigue en la lisa y asi ir metiendolos de a uno
  }//el devuelve contenido de linea es porq necesito poner un char para reutilizar la funcion de inserta en archivo
return a;/// para que compile
}
*/
//---------------------------------------------------------------------

archivo IFArchivo (archivo a,char *nombreArchivo, char *texto){
  archivo aux = buscaArchivo(a, nombreArchivo);
  if (aux != NULL){
    return insertaEnArchivo (aux, texto);
  }
  else
    return a;
}

//---------------------------------------------------------------------

archivo TYPEArchivo(archivo a, char *nombreArchivo){
  archivo aux = buscaArchivo(a, nombreArchivo);
  if (aux != NULL){
    imprimirLineas (aux->cont);
  }
  return a;
}

//---------------------------------------------------------------------

bool existeArchivo (archivo a, char *nombreArchivo){
  if (strcmp(a->nombreArchivo, nombreArchivo) == 0)
    return true;
  else if (strcmp(a->nombreArchivo, nombreArchivo) != 0){
    if (a->sig == NULL)
      return false;
    else
      existeArchivo (a->sig, nombreArchivo);
  }
  return false;
}
