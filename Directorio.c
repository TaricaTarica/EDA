#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "Directorio.h"
#include "Archivo.h"
#include "define.h"


struct nodoDirectorio{
    char *nombreDirectorio;
    archivo a;
    directorio sig;
    directorio hijo;
    directorio padre;
};

directorio create_Raiz(directorio d){
  if(d == NULL){
    directorio aux = new(nodoDirectorio);
    aux->nombreDirectorio = new char[strlen("raiz") + 1];
    strcpy(aux->nombreDirectorio, "raiz");
    aux->a = NULL;
    aux->sig = NULL;
    aux->hijo = NULL;
    aux->padre = NULL;
    return aux;
  }
  else
    return d;
}

//---------------------------------------------------------------------

directorio create_Directorio(directorio d, char *cadena){
  char *parametro = strtok (cadena,"/");
  char *nombreDir;
  while (parametro != NULL){
    strcpy(nombreDir,parametro);
    parametro = strtok(NULL,"/");
    if (parametro != NULL)
      d = busca_directorio (d, parametro);
    }
    directorio aux = new (nodoDirectorio);
    if (d->hijo == NULL){
      aux->nombreDirectorio = nombreDir;
      aux->a = NULL;
      aux->sig = NULL;
      aux->hijo = NULL;
      aux->padre = d;
      return d;
    }
    else{
      aux = d->hijo;
      while (d->hijo != NULL){
        aux = aux->sig;
      }
      directorio aux1 = aux;
      aux->nombreDirectorio = nombreDir;
      aux->a = NULL;
      aux->sig = NULL;
      aux->hijo = NULL;
      aux->padre = d;
      aux1->sig = aux;
      return d;
    }
  return d;
}

//---------------------------------------------------------------------

directorio busca_directorio(directorio d, char *parametro){
  if (strcmp(d->nombreDirectorio, parametro) == 0)
    return d->hijo;
  else if(d->sig != NULL)
    return busca_directorio(d->sig, parametro);
    else{
      printf("no se encontró un directorio con ese nombre");
      return NULL;
    }
}

//---------------------------------------------------------------------

void print_Directorio(directorio d){
  directorio dirAUX = d;
  do{
    printf("+ %s", dirAUX->nombreDirectorio);
    printf("\n");
    printf("\t \t");
    print_Archivo(dirAUX->a);
    dirAUX = dirAUX->sig;
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
  printf("2");
  d->a =  BFarchivo (d->a, nombreArchivo, k);
  return d;
}

//---------------------------------------------------------------------

directorio CDdir (directorio d, char*nombreDir){
}

//---------------------------------------------------------------------
/*directorio CATDirectorio(directorio d, char *nombreArchivo1, char *nombreArchivo2){
  d->a = Concat(d->a, nombreArchivo1, nombreArchivo2);
  return d;
}*/

//---------------------------------------------------------------------
bool DIRpertenece (directorio d, char * nombreDir){
	if (d == NULL)
		return false;
	else{
		if (strcmp(d->nombreDirectorio, nombreDir) == 0)
			return true;
		else return DIRpertenece(d->hijo, nombreDir) || DIRpertenece(d->sig, nombreDir);
	}
}

