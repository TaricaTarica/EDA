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
			  printf("-Directorio %s creado con exito\n", aux->nombreDirectorio);
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
				aux->sig = iter->hijo;
				aux->padre = iter;
				aux->hijo = NULL;
				iter->hijo = aux;
				printf("-Directorio %s creado con exito\n", aux->nombreDirectorio);
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
  return false;
}


//---------------------------------------------------------------------

directorio busca_directorio(directorio d, char *parametro){
    if (strcmp(d->nombreDirectorio, parametro) == 0){
      return d->hijo;
    }
    else if(d->sig != NULL)
      return busca_directorio(d->sig, parametro);
    else{
        printf("no se encontró un directorio con ese nombre");
        return NULL;
    }

}

//---------------------------------------------------------------------

/*void print_Directorio(directorio d){
  if(d != NULL){
    printf("  + %s", d->nombreDirectorio);
    printf("\n");
    printf("\t");
    print_Archivo(d->a);
    if (d->hijo != NULL){
      printf("\t");
      printf("hijo de %s : ", d->nombreDirectorio);
      print_Directorio(d->hijo);

    }
    if(d->sig != NULL){
      printf("\t");
      print_Directorio(d->sig);
    }
  }
}*/

void print_Directorio(directorio d, int cont){
  for (int auxcont = cont  ; auxcont > 0 ; auxcont --){
    if (auxcont > 1){
      printf ("\t");
    }
    else{
      printf("└───────");
    }
  }
  printf("► %s", d->nombreDirectorio);
  printf("\n");
  cont ++;
  if (d->a != NULL){
    print_Archivo(d->a, cont);
  }
  if (d->hijo != NULL){
    print_Directorio (d->hijo, cont);
  }
  if (d->sig != NULL)
    print_Directorio (d->sig, cont-1);
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
if(iter != NULL){
    while (pch != NULL)
    {
      pch = strtok (NULL,"/");
      if(pch == NULL){
        return iter;
      }
      else{
        iter = iter->hijo;
        while(pch != NULL){
          while ((iter != NULL) && (strcmp (pch, iter->nombreDirectorio) != 0))
            iter = iter->sig;
          if ((iter != NULL) && (strcmp (pch, iter->nombreDirectorio) == 0)){
            pch = strtok (NULL,"/");
            if(pch != NULL){
              iter = iter->hijo;
            }
            else{
              return iter;
            }
          }
          else{
            while(pch != NULL)
              pch = strtok (NULL,"/");
            printf("!: No se encontró el directorio especificado\n");
            return d;
          }
        }
      }
    }
  }
  return d;
} //mirá qué código papá

//---------------------------------------------------------------------

 directorio CDpadredir (directorio d){
   if (d->padre != NULL)
    return d->padre;
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

  if (d->padre != NULL){
    PWDir(d->padre, nombreDirectorio);
  }
  printf("/%s", d->nombreDirectorio);
}

//---------------------------------------------------------------------
bool RMDIR_dir(directorio &d, char* parametro){
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
	    directorio soyHijo=d;
	    directorio soyTuPadre = d; //se que empieza en raiz, por eso apunto al hijo.
	    soyHijo = new (nodoDirectorio);
	    soyHijo->nombreDirectorio = new char [strlen(nombre) + 1];
 	    strcpy(soyHijo->nombreDirectorio, nombre);
	    auxPATH = strtok (path,"/");
	    while(auxPATH != NULL){
		auxPATH = strtok (NULL,"/");
		if(auxPATH == NULL){
		  soyHijo->sig = soyTuPadre->hijo->sig; //guardo el hermano
			soyHijo->padre = soyTuPadre; //guardo al padre
			soyTuPadre->hijo = soyHijo; //guardo al hijo actual (el que quiero eliminar)
			printf("-Directorio %s eliminado con exito\n", soyHijo->nombreDirectorio);	
			delete (soyHijo);		
			soyHijo=NULL;
			soyTuPadre->hijo=soyTuPadre->hijo->sig ;
			return true;
		}
		else{
		  soyTuPadre = soyTuPadre ->hijo;
		  while(soyTuPadre != NULL){
		    while(soyTuPadre->sig != NULL && (strcmp(soyTuPadre->nombreDirectorio, auxPATH) != 0)){
		      soyTuPadre = soyTuPadre->sig;
		    }
		    if(soyTuPadre != NULL && (strcmp(soyTuPadre->nombreDirectorio, auxPATH) == 0)){
		      auxPATH = strtok (NULL,"/");
		      if(auxPATH != NULL){
			soyTuPadre = soyTuPadre->hijo;
		      }
		      else{
			soyHijo->sig = soyTuPadre->hijo->sig; //guardo el hermano
			soyHijo->padre = soyTuPadre; //guardo al padre
			soyTuPadre->hijo = soyHijo; //guardo al hijo actual (el que quiero eliminar)
			printf("-Directorio %s eliminado con exito\n", soyHijo->nombreDirectorio);	
			delete (soyHijo);		
			soyHijo=NULL;
			soyTuPadre->hijo=soyTuPadre->hijo->sig ;
			return true;
		      }
		   }
		  }
		}
             }
	      
	return 0;
}

