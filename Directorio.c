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

directorio create_Directorio(directorio d, char *cadena){
  printf("ENTRA A LA FUNCION");
  char *nombreDir = new char[strlen(cadena) + 1];
  char *parametro = new char[strlen(cadena) + 1];
  parametro = strtok (cadena,"/");
  printf ("%s",parametro);
  strcpy(nombreDir,parametro);
  directorio dAUX = d;
  while (dAUX != NULL){
    printf("--");
    strcpy(nombreDir,parametro);
    parametro = strtok(NULL,"/");
    printf ("%s",parametro);
    if (parametro != NULL){
      dAUX = busca_directorio (dAUX, parametro); //la función retorna null. puede que esté mal buscaDirectorio.
      strcpy(nombreDir,parametro);
    }//de acá parriba ok,
  }
  printf ("%s",nombreDir);

  directorio aux = new (nodoDirectorio);
  if (dAUX == NULL){
    aux->nombreDirectorio = new char[strlen(nombreDir) + 1]; //FALTABA ESTO°°
    strcpy(aux->nombreDirectorio, nombreDir);
    aux->a = NULL;
    aux->sig = NULL;
    aux->hijo = NULL;
    aux->padre = d;
    d->hijo = aux;
    return d;
  }
  else{
    aux = d->hijo;
    while (d->hijo != NULL){
      aux = aux->sig;
    }
    directorio aux1 = aux;
    aux->nombreDirectorio = new char[strlen(nombreDir) + 1]; //FALTABA ESTO°°
    strcpy(aux->nombreDirectorio, cadena);
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
  if(dirAUX != NULL){
    printf("+ %s", dirAUX->nombreDirectorio);
    printf("\n");
    printf("\t \t");
    print_Archivo(dirAUX->a);
    if (dirAUX->hijo != NULL){
      print_Directorio(dirAUX->hijo);
    }
    if(dirAUX->sig != NULL){
      print_Directorio(dirAUX->sig);
    }
  }
  if(dirAUX->sig != NULL){
    dirAUX = dirAUX->sig;
    print_Directorio(dirAUX);
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
	directorio auxdir = d;
	if(d != NULL){
		auxdir = busca_directorio(d, nombreDir);
		if(auxdir != NULL){ //lo encontre
			return auxdir; //si encontré el directorio entonces lo devuelvo.
		}
	}
  else
    return auxdir;
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
