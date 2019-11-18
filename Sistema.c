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
	    if(sisAUX->d == NULL){
	      return ERROR;
	    }
	    else{
	      sisAUX->dir_act = CDdir (sisAUX->d, nombreDirectorio);
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
      PWDir (sisAUX->d, get_nDirectorio(sisAUX->dir_act));
      return OK;
    }
    return ERROR;
  }
}

//---------------------------------------------------------------------

TipoRet RMDIR (Sistema &s, char* nombreDirectorio){
	if(s == NULL)
	    return ERROR;
	else{
	    Sistema sisAUX = s;
	    if(sisAUX->d == NULL){
	      return ERROR;
	}
	else{
	      RMDIR_dir(sisAUX->d,nombreDirectorio);
	      return OK;
	}
	    return ERROR;
	  }
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
        print_Directorio(sisAUX->d);
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
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      sisAUX->d = CreateArchivoDirectorio(sisAUX->d, nombreArchivo, tamanio);
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
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      sisAUX->d = IFDirectorio(sisAUX->d, nombreArchivo, texto);
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
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      sisAUX->d = TYPEDirectorio(sisAUX->d, nombreArchivo);
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
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      sisAUX->d = DELETEArchivoDirectorio(sisAUX->d, nombreArchivo);
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
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      printf("1");
      sisAUX->d = BFDirectorio(sisAUX->d, nombreArchivo, k);
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
