#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "gestor.h"

using namespace std;

int main(){
  sistema s = createSistema();
  createRaiz(s);
  directorio aux = new (nodo_directorio);
  aux->a = NULL;
  aux = s->d;
  printf("Carpeta raíz: %s ", aux->nombre);
}
