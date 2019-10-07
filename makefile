todo: main.o linea.o archivo.o directorio.o sistema.o
	g++ -Wall -o main main.o linea.o archivo.o directorio.o sistema.o
main.o: main.c
	g++ -Wall -c main.c
linea.o: Linea.c
		g++ -Wall -c Linea.c
archivo.o: Archivo.h Archivo.c
	g++ -Wall -c Archivo.c
directorio.o: Directorio.h Directorio.c
	g++ -Wall -c Directorio.c
sistema.o: Sistema.h Sistema.c
	g++ -Wall -c Sistema.c
clean:
	rm -f *.o
	rm -f main
