#include <stddef.h>
#include <stdio.h>
#include "define.h"
#include "Linea.h"

struct nodo_linea{
    char *linea
    linea sig;
};


linea insertaLinea (linea ln, char *texto);

  if (ln->linea == NULL){
    linea aux = new(nodo_linea);
    aux->linea = new char[strlen(texto) + 1];
    strcpy(aux->linea, texto);
    return ln;
  }
  else
    ln->sig = insertaLinea (ln->sig, texto);
}

//---------------------------------------------------------------------

int cantLineas (linea ln){
  if (ln->linea == NULL)
    return 0;
  else if (ln->linea != NULL)
    return 1 + cantLineas(ln->sig);
}

//---------------------------------------------------------------------

void imprimirLineas (linea ln){
  if (ln->linea == NULL)
    return 0;
  else if (ln->linea != NULL)
    cout << ln->linea << " ";
    return imprimirLineas(ln->sig);

}
