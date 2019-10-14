#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Sistema.h"

using namespace std;

int main(){
	Sistema s = create_Sistema();
	bool salir = false;
	char * comando = new(char[MAX_COMANDO]);
	char * parametro = new(char[MAX_PARAMETRO]);
	char * parametro1 = new(char[MAX_PARAMETRO]);
	int parametro_num;
	TipoRet retorno;

	do{
		cout << "> ";
		cin >> comando;
		if (strcmp(comando,"DIR") == 0){
			fgets(parametro, MAX_PARAMETRO, stdin);
			retorno = DIR (s);
		}else if (strcmp(comando,"CREATE") == 0){
			fgets(parametro, MAX_PARAMETRO, stdin);
			retorno = CREATE (s, parametro);
		}else if (strcmp(comando,"DELETE") == 0){
			fgets(parametro, MAX_PARAMETRO, stdin);
			retorno = DELETE (s, parametro);
		}/*else if (strcmp(comando,"UNDELETE") == 0){
			retorno = UNDELETE (s);
		}else if (strcmp(comando,"IC") == 0){
			cin >> parametro;
			fgets(parametro1, MAX_PARAMETRO, stdin);
			retorno = IC (s, parametro, parametro1);
		}*/else if (strcmp(comando,"IF") == 0){
			cin >> parametro;
			fgets(parametro1, MAX_PARAMETRO, stdin);
			retorno = IF (s, parametro, parametro1);
		}/*else if (strcmp(comando,"BC") == 0){
			cin >> parametro;
			cin >> parametro_num;
			retorno = BC (s, parametro, parametro_num);
		}*/else if (strcmp(comando,"BF") == 0){
			cin >> parametro;
			cin >> parametro_num;
			retorno = BF (s, parametro, parametro_num);
		}else if (strcmp(comando,"CAT") == 0){
			cin >> parametro;
			cin >> parametro1;
			retorno = CAT (s, parametro, parametro1);
		}else if (strcmp(comando,"TYPE") == 0){
			cin >> parametro;
			retorno = TYPE (s, parametro);
		}else if (strcmp(comando,"salir") == 0){
			cout << "\t- CHAUUUUU!!!\n\n";
			salir = true;
		}else
			cout << " - Comando Incorrecto.\n\n";

		if (retorno == OK)
			cout << " - OK\n\n";
		else if (retorno == ERROR)
			cout << " - ERROR\n\n";
		else
			cout << " - NO IMPLEMENTADA\n\n";
	}while (!salir);

	/*s = DESTRUIR_SISTEMA ();
	delete [] comando;
	delete [] parametro;
	delete [] parametro1;
  return 0;*/
}
