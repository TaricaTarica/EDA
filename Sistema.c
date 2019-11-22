#include <stddef.h>
#include <stdio.h>

#include "Sistema.h"
#include "define.h"
#include "Linea.h"
#include "Archivo.h"
#include "Directorio.h"

struct nodoSistema{
    directorio d;
    directorio dir_act;
};

Sistema create_Sistema(){
  Sistema s = new(nodoSistema);
  s->d = NULL;
  s->d = create_Raiz(s->d);
  s->dir_act = s->d;
  return s;
}

//---------------------------------------------------------------------

TipoRet MKDIR (Sistema &s, char *cadena){
  if(s == NULL){
    return ERROR;
  }
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL)
      return ERROR;
    else{
      if(createDirectorio(sisAUX->d,cadena))
        return OK;
      else
        return ERROR;
    }
  }
}

//---------------------------------------------------------------------

TipoRet CD (Sistema &s, char* nombreDirectorio){
	  if(s == NULL)
	    return ERROR;
	  else{
	    Sistema sisAUX = s;
	    if(sisAUX->dir_act == NULL){
	      return ERROR;
	    }
	    else{
	      sisAUX->dir_act = CDdir (sisAUX->dir_act, nombreDirectorio);
		    return OK;
	    }
	    return ERROR;
    }
}

//---------------------------------------------------------------------

TipoRet CDpadre (Sistema &s){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      sisAUX->dir_act = CDpadredir (sisAUX->dir_act);
      return OK;
    }
    return ERROR;
  }
}

//---------------------------------------------------------------------

TipoRet PWD(Sistema &s){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      PWDir (sisAUX->dir_act, get_nDirectorio(sisAUX->dir_act));
      return OK;
    }
    return ERROR;
  }
}

//---------------------------------------------------------------------

TipoRet RMDIR (Sistema &s, char* nombreDirectorio){
	return NO_IMPLEMENTADA;
}

//---------------------------------------------------------------------

TipoRet COPY(Sistema &s, char* archidirOrigen, char* directorioDestino){
	return NO_IMPLEMENTADA;

}

//---------------------------------------------------------------------

TipoRet DIR (Sistema &s){
    if(s == NULL){
      return ERROR;
    }
    else{
      Sistema sisAUX = s;
      if(sisAUX->d == NULL)
        return ERROR;
      else{
        print_Directorio(sisAUX->d, 0);
        return OK;
      }
    }
}

//---------------------------------------------------------------------

TipoRet CREATE (Sistema &s, char *nombreArchivo, int tamanio){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      sisAUX->dir_act = CreateArchivoDirectorio(sisAUX->dir_act, nombreArchivo, tamanio);
      return OK;
    }
  }
}

//---------------------------------------------------------------------

TipoRet IF (Sistema &s, char *nombreArchivo, char *texto){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      sisAUX->dir_act = IFDirectorio(sisAUX->dir_act, nombreArchivo, texto);
        return OK;
    }
    return ERROR;
  }
}

//---------------------------------------------------------------------

TipoRet TYPE (Sistema &s, char *nombreArchivo){ //me calente y me fui a comer

  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      sisAUX->dir_act= TYPEDirectorio(sisAUX->dir_act, nombreArchivo);
      return OK;
    }
    return ERROR;
  }

}

//---------------------------------------------------------------------

TipoRet DELETE (Sistema &s, char *nombreArchivo){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      sisAUX->dir_act = DELETEArchivoDirectorio(sisAUX->dir_act, nombreArchivo);
      return OK;
    }
    return ERROR;
  }
}

//---------------------------------------------------------------------

TipoRet BF (Sistema &s, char *nombreArchivo, int k){
  printf("0");
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->dir_act == NULL){
      return ERROR;
    }
    else{
      printf("1");
      sisAUX->dir_act= BFDirectorio(sisAUX->dir_act, nombreArchivo, k);
      return OK;
    }
  }
}

//---------------------------------------------------------------------

/*TipoRet CAT (Sistema &s, char *nombreArchivo1, char *nombreArchivo2){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      sisAUX->d = CATDirectorio(sisAUX->d, nombreArchivo1, nombreArchivo2);
      return OK;
    }
  }
}*/
