#include <stddef.h>
#include <stdio.h>

#include "Sistema.h"
#include "define.h"
#include "Directorio.h"
#include "Archivo.h"


struct nodoSistema{
    directorio d;
    //direcotrioActual da;
};

Sistema create_Sistema(){
  Sistema s = new(nodoSistema);
  s->d = NULL;
  return s;
}

//---------------------------------------------------------------------

TipoRet DIR (Sistema &s){
    if(s == NULL)
      return ERROR;
    else{
      Sistema sisAUX = s;
      if(sisAUX->d == NULL)
        return ERROR;
      else{
        directorio dirAUX = sisAUX->d;
        print_Directorio(dirAUX);
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
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = insert_Archivo(arAUX, nombreArchivo, tamanio); //porq no usas arAux en vez de  dirAUX->a? - no me había dado cuenta, arreglado.
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
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = buscaArchivo(arAUX, nombreArchivo);
      if (arAUX != NULL){
        insertaEnArchivo (arAUX, nombreArchivo, texto);
        return OK;
      }
      else
        return ERROR;
    }
  }
}

//---------------------------------------------------------------------

TipoRet TYPE (Sistema &s, char *nombreArchivo){

  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = buscaArchivo(arAUX, nombreArchivo);
      if (arAUX != NULL){
      linea lnAUX = arAUX->cont;
        imprimirLineas (lnAUX);
        return OK;
      }
      else
        return ERROR;
    }
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
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = eliminar_Archivo(arAUX, nombreArchivo);
      return OK;
    }
  }
}

//---------------------------------------------------------------------

TipoRet BF (Sistema &s, string nombreArchivo, int k){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = eliminar_CantLineas(arAUX, nombreArchivo, k);
      return OK;
    }
  }
}

//---------------------------------------------------------------------

TipoRet CAT (Sistema &s, string nombreArchivo1, string nombreArchivo2){
  if(s == NULL)
    return ERROR;
  else{
    Sistema sisAUX = s;
    if(sisAUX->d == NULL){
      return ERROR;
    }
    else{
      directorio dirAUX = sisAUX->d;
      archivo arAUX = dirAUX->a;
      arAUX = Concat(arAUX, nombreArchivo1, nombreArchivo2);
      return OK;
    }
  }
}
