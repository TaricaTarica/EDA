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
			cout << "nombre del archivo: ";
			cin >> parametro;
			cout << "tamanio: ";
			cin >> parametro_num;
			retorno = CREATE (s, parametro, parametro_num);
		}else if (strcasecmp(comando,"MKDIR") == 0){
			cout << "ruta: ";
			cin >> parametro;
			/* lo que me dijo el zabalsa, path guarda la cadena y nombre el elemento a insert_Archivo
					anda rico, pero hay que ver como meterlo en la funcion, esta en el main para probarlo nomas.
					se podria saltar el paso de agarrar elem al principio,
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

		cout << "path=" << path << endl;
		cout << "nombre=" << nombre << endl;
		*/

//			retorno = MKDIR (s, parametro);
		}else if (strcmp(comando,"DELETE") == 0){
			cout << "nombre del archivo: ";
			cin >> parametro;
			retorno = DELETE (s, parametro);
		}/*else if (strcmp(comando,"UNDELETE") == 0){
			retorno = UNDELETE (s);
		}else if (strcmp(comando,"IC") == 0){
			cin >> parametro;
			fgets(parametro1, MAX_PARAMETRO, stdin);
			retorno = IC (s, parametro, parametro1);
		}*/else if (strcmp(comando,"IF") == 0){
			cout << "nombre del archivo: ";
			cin >> parametro;
			cout << "linea a insertar: ";
			cin >> parametro1;
			retorno = IF (s, parametro, parametro1);
		}/*else if (strcmp(comando,"BC") == 0){
			cin >> parametro;
			cin >> parametro_num;
			retorno = BC (s, parametro, parametro_num);
		}*/else if (strcmp(comando,"BF") == 0){
			cout << "nombre del archivo: ";
			cin >> parametro;
			cout << "lineas a borrar: ";
			cin >> parametro_num;
			retorno = BF (s, parametro, parametro_num);
		}/*else if (strcmp(comando,"CAT") == 0){
			cin >> parametro;
			cin >> parametro1;
			retorno = CAT (s, parametro, parametro1);
		}*/else if (strcmp(comando,"TYPE") == 0){
			cout << "nombre del archivo: ";
			cin >> parametro;
			retorno = TYPE (s, parametro);
		}else if (strcmp(comando,"CD") == 0){
			cout << "ruta: ";
			cin >> parametro;
			retorno = CD (s, parametro);
		}else if (strcmp(comando,"RMDIR") == 0){
			cout << "ruta: ";
			cin >> parametro;
			retorno = RMDIR (s, parametro);
		}else if (strcmp(comando,"PWD") == 0){
			retorno = PWD (s);
		}else if (strcmp(comando,"salir") == 0){
			cout << "\t- CHAUUUUU!!!\n\n";
			salir = true;
		}else
			cout << " - Comando Incorrecto.\n\n";

		if (retorno == OK)
			cout << " - OK\n\n";

	}while (!salir);



	/*s = DESTRUIR_SISTEMA ();
	delete [] comando;
	delete [] parametro;
	delete [] parametro1;
  return 0;*/
}
