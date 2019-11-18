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
  char * auxPATH = new char [strlen(path) + 1];
  strcpy(auxPATH,path);
  char * elem = new char [strlen(path) + 1];
  char * elemAUX = new char [strlen(path) + 1];
  char * pch = new char [strlen(path) + 1];
  elemAUX = strtok (path,"/");
  while (elemAUX != NULL){
    elemAUX = strtok(NULL,"/");
    if(elemAUX != NULL)
      strcpy(elem,elemAUX);
  //aca hay que poner el busca directorio para ver que no cree uno q ya existe
  } //obtengo el nombre del nuevo directorio
  printf("DIRECTORIO A INSERTAR: %s\n",elem);
  pch = strtok (auxPATH,"/");
  printf("PCH: %s\n", pch);
	while (pch != NULL)
	{
		pch = strtok (NULL, "/");
    while ((iter->sig != NULL) && (strcmp (pch, iter->nombreDirectorio) != 0) && (pch != NULL)/* && (strcmp (pch, elem) != 0)*/){
        printf("PCH ES: %s\n", pch);
        printf("ITER ES: %s\n",iter->nombreDirectorio);
        printf("si entro aca deberia cambiar iter\n");
        iter = iter->sig;
    }
		if (iter == NULL)
			return false;
    printf("PCH : %s\n", pch);
		if ((pch != NULL) && (strcmp(elem, pch) != 0)){
      printf("ENTRO IF");
		  iter = iter->hijo;
      printf("ITER ES: %s\n",iter->nombreDirectorio);
    }

	}
  printf("AL SALIR PCH ES: %s\n", pch);
  printf("AL SALIR ITER ES: %s\n",iter->nombreDirectorio);
  aux = new (nodoDirectorio);
	aux->nombreDirectorio = new char [strlen(elem) + 1];
  strcpy (aux->nombreDirectorio, elem);
	aux->hijo = NULL;
	if (d == NULL)
	{
		aux->hijo = NULL;
		aux->sig = NULL;
		aux->padre = NULL;
		d = aux;
	}
	else
	{
		aux->padre = iter;
		aux->hijo = NULL;
		aux->sig = iter->hijo;
		iter->hijo = aux;
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
 void RMDIR_dir(directorio d, char* nombreDirectorio){
	char * elem = new char [strlen(nombreDirectorio) + 1];
  	char * elemAUX = new char [strlen(nombreDirectorio) + 1];
 	char * papi = new char [strlen(nombreDirectorio) + 1];
	directorio iter = d;
	elemAUX = strtok (nombreDirectorio,"/");
	if (d!=NULL){

		  while (elemAUX != NULL){
		    elemAUX = strtok(NULL,"/");
		    if(elemAUX != NULL)
		      strcpy(elem,elemAUX);
		  } //obtengo el nombre del nuevo directorio

		  char * pch = strtok (nombreDirectorio,"/");
			while (pch != NULL)// creo q siempre esta tomando valr null despues de la primer pasada
			{
		    while (strcmp (pch, iter->nombreDirectorio) != 0 && iter->sig != NULL){//pero imprime solo el primero siempre (raiz)
			iter = iter->sig;
		    }
		    strcpy(papi ,iter->nombreDirectorio);
				pch = strtok (NULL, "/");
		  }
	   printf("nombredir= %s\n", papi);
           printf("elem= %s\n", elem);
	   delete elem;
	   iter= d->padre;
	   d->hijo= NULL;

	   elem= NULL;
           printf("elem ya borrado= %s\n", elem);
            printf("elemAUX= %s\n", elemAUX);


	}

}
