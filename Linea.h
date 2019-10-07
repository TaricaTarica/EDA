#ifndef LINEA_H
#define LINEA_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "define.h"

typedef struct nodo_linea * Linea;

linea insertaLinea (linea ln, char *nombreArchivo, char *texto);

int cantLineas (linea ln);

void imprimirLineas (linea ln);

#endif
