#include <stddef.h>
#include <stdio.h>

#include "Sistema.h"
#include "define.h"
#include "Directorio.h"
#include "Archivo.h"


struct nodoSistema{
    directorio d;
};

Sistema create_Sistema(){
  Sistema s = new(nodoSistema);
  s->d = NULL;
  return s;
}

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
TipoRet CREATE (Sistema &s, char *nombreArchivo){
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
      dirAUX->a = insert_Archivo(arAUX, nombreArchivo);
      return OK;
    }
  }
}
