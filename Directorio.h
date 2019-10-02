#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

typedef struct nodoDirectorio * directorio;

directorio insert_Directorio(directorio d, char *nDirectorio);

directorio create_Raiz(directorio d);

#endif
