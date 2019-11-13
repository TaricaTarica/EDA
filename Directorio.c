#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
bool createDirectorio (directorio & d,char * path){
	directorio aux;
	directorio iter = d;
  char * elem = new char [strlen(path) + 1];
  char * elemAUX = new char [strlen(path) + 1];
  elemAUX = strtok (path,"/");
  while (elemAUX != NULL){
    elemAUX = strtok(NULL,"/");
    if(elemAUX != NULL)
      strcpy(elem,elemAUX);
  } //obtengo el nombre del nuevo directorio

  char * pch = strtok (path,"/");
	while (pch != NULL)
	{
		while ((iter != NULL) && (strcmp (pch, iter->nombreDirectorio) != 0))
				iter = iter->hijo;
		if (iter == NULL)
			return false;
		pch = strtok (NULL, "/");
		if (pch != NULL)
			iter = iter->sig;
	}
  aux = new (nodoDirectorio);
	aux->nombreDirectorio = new char [strlen(elem) + 1];

  strcpy (aux->nombreDirectorio, elem);
	aux->sig = NULL;
	if (d == NULL)
	{
		aux->sig = NULL;
		aux->hijo = NULL;
		aux->padre = NULL;
		d = aux;
	}
	else
	{
		aux->padre = iter;
		aux->sig = NULL;
		aux->hijo = iter->sig;
		iter->sig = aux;
	}
	return true;
}


//---------------------------------------------------------------------

directorio busca_directorio(directorio d, char *parametro){
    if (strcmp(d->nombreDirectorio, parametro) == 0){
      return d->hijo;
      printf("aca entre?????\n");
    }
    else if(d->sig != NULL)
      return busca_directorio(d->sig, parametro);
    else{
        printf("no se encontró un directorio con ese nombre");
        return NULL;
    }

}

//---------------------------------------------------------------------

void print_Directorio(directorio d){
  //directorio dirAUX = d;
  if(d != NULL){
    printf("+ %s", d->nombreDirectorio);
    printf("\n");
    printf("\t \t");
    print_Archivo(d->a);
    if (d->hijo != NULL){
      printf("\t \t");
      print_Directorio(d->hijo);
    }
    if(d->sig != NULL){
      print_Directorio(d->sig);
    }
  }
}

  /*do{
    printf("+ %s", dirAUX->nombreDirectorio);
    printf("\n");
    printf("\t \t");
    print_Archivo(dirAUX->a);
    printf("+ %s", dirAUX->hijo->nombreDirectorio);
    dirAUX->sig;
  }while (d->sig != NULL);
  printf("\n");
}

if(aux != NULL){
    printf("- %s", aux->nombreArchivo);
    printf("\n");
    if (aux->sig != NULL){
      aux = aux->sig;
      printf("\t \t");
      print_Archivo(aux);
    }
}
else{
  printf("\n");
}*/

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
	directorio iter = d;
  char * pch = strtok(nombreDir, "/");
	if(d != NULL){
    while (pch != NULL)
    {
      while ((iter != NULL) && (strcmp (pch, iter->nombreDirectorio) != 0))
          iter = iter->hijo;
      if (iter == NULL)
        return d;
      pch = strtok (NULL, "/");
      if (pch != NULL)
        iter = iter->sig;
    }
    return iter;
  }
  else
    return d;
}


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
//---------------------------------------------------------------------
char* nombreDirectorio(directorio d){
  return d->nombreDirectorio;
}
