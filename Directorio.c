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
bool createDirectorio (directorio & d,char * parametro){
 char * path = new char[MAX_PARAMETRO];
		char * nombre = new char[MAX_PARAMETRO];
		strcpy(path, "");
		strcpy(nombre, "");
		char primer_caracter = parametro[0];
		char * pch = strtok (parametro,"/");
		while (pch != NULL)
		{
			strcat(path, nombre);
			strcat(path, "/");
			strcpy(nombre, pch);
			pch = strtok (NULL, "/");
		}
		if (primer_caracter != '/')
		  path = &path[1];
		path[strlen(path)-1] = '\0';
		printf("path= %s", path);
		printf("nombre= %s", nombre);
	    char * auxPATH = new char [strlen(path) + 1];
	    strcpy(auxPATH,path);
	    directorio aux;
	    directorio iter = d; //se que empieza en raiz, por eso apunto al hijo.
	    auxPATH = strtok (path,"/");
	    while(auxPATH != NULL){
		auxPATH = strtok (NULL,"/");
		if(auxPATH == NULL){
		  aux = new (nodoDirectorio);
			aux->nombreDirectorio = new char [strlen(nombre) + 1];
		  strcpy(aux->nombreDirectorio, nombre);
		  aux->sig = iter->hijo;
		  aux->padre = iter;
		  aux->hijo = NULL;
		  iter->hijo = aux;
		  return true;
		}
		else{
		  iter = iter ->hijo;
		  printf("ITER =%s\n",iter->nombreDirectorio);
		  while(iter != NULL){
		    printf("ENTRO AL WHILE\n");
		    while(iter->sig != NULL && (strcmp(iter->nombreDirectorio, auxPATH) != 0)){
		      iter = iter->sig;
		      printf("\nVALOR ITER DENTRO DEL WHILE: %s\n",iter->nombreDirectorio);
		    }
		    if(iter != NULL && (strcmp(iter->nombreDirectorio, auxPATH) == 0)){

		      auxPATH = strtok (NULL,"/");
		      if(auxPATH != NULL){
			printf("ENTRO IF\n");
			iter = iter->hijo;
		      }
		      else{
			printf("CREO NUEVO NODO Y TAL\n");
			printf("ITER =%s\n",iter->nombreDirectorio);
			aux = new (nodoDirectorio);
			aux->nombreDirectorio = new char [strlen(nombre) + 1];
			strcpy(aux->nombreDirectorio, nombre);
			aux->sig = iter->hijo;
			aux->padre = iter;
			aux->hijo = NULL;
			iter->hijo = aux;
			return true;
		      }
		    }
		    else{
		      while(auxPATH != NULL)
			auxPATH = strtok (NULL,"/");
		      return false;
		    }
		  }
		}
	      }
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
      printf("hijo de %s : ", d->nombreDirectorio);
      print_Directorio(d->hijo);
    }
    if(d->sig != NULL){
      print_Directorio(d->sig);
    }
  }
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
char* get_nDirectorio(directorio d){
  return d->nombreDirectorio;
}
//---------------------------------------------------------------------
void PWDir (directorio d, char * nombreDirectorio){
  printf("%s/", get_nDirectorio(d));
  while (d != NULL)
  {
    while ((d->hijo != NULL) && (strcmp (nombreDirectorio, d->nombreDirectorio) != 0)){
        printf("ENTRO SEGUNDO WHILE");
        d = d->hijo;
        printf("%s/", get_nDirectorio(d));
    }
    d = d->sig;
  }
    if(strcmp("raiz",nombreDirectorio) != 0)
      printf("%s/", nombreDirectorio);
}

//---------------------------------------------------------------------
bool RMDIR_dir(directorio d, char* parametro){
	char * path = new char[MAX_PARAMETRO];
		char * nombre = new char[MAX_PARAMETRO];
		strcpy(path, "");
		strcpy(nombre, "");
		char primer_caracter = parametro[0];
		char * pch = strtok (parametro,"/");
		while (pch != NULL)
		{
			strcat(path, nombre);
			strcat(path, "/");
			strcpy(nombre, pch);
			pch = strtok (NULL, "/");
		}
		if (primer_caracter != '/')
		  path = &path[1];
		path[strlen(path)-1] = '\0';
	    char * auxPATH = new char [strlen(path) + 1];
	    strcpy(auxPATH,path);
	    directorio aux=d;
	    directorio iter = d; //se que empieza en raiz, por eso apunto al hijo.
	    auxPATH = strtok (path,"/");
	    while(auxPATH != NULL){
		auxPATH = strtok (NULL,"/");
		if(auxPATH == NULL){
		  aux = new (nodoDirectorio);
		  aux->nombreDirectorio = new char [strlen(nombre) + 1];
		  strcpy(aux->nombreDirectorio, nombre);
		  aux->padre = iter;
		  aux->hijo = NULL;
		  iter->hijo = aux;
		  delete (aux);
		  return true;
		}
		else{
		  iter = iter ->hijo;
		  while(iter != NULL){
		    while(iter->sig != NULL && (strcmp(iter->nombreDirectorio, auxPATH) != 0)){
		      iter = iter->sig;
		    }
		    if(iter != NULL && (strcmp(iter->nombreDirectorio, auxPATH) == 0)){

		      auxPATH = strtok (NULL,"/");
		      if(auxPATH != NULL){
			iter = iter->hijo;
		      }
		      else{
			aux = new (nodoDirectorio);
			aux->nombreDirectorio = new char [strlen(nombre) + 1];
		 	strcpy(aux->nombreDirectorio, nombre);
			aux->sig = NULL;
			aux->padre = iter;
			//aux->hijo = NULL;
			iter->hijo = aux;	
			delete aux;
			return true;
		      }
		    }
		    else{
		      while(auxPATH != NULL)
			auxPATH = strtok (NULL,"/");
		      return false;
		    }
		  }
		}
	      }

}
