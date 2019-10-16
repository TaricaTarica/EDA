todo: main.o sistema.o directorio.o archivo.o linea.o
	g++ -Wall -o main main.o  Sistema.o Directorio.o Archivo.o Linea.o
main.o: main.c
	g++ -Wall -c main.c
sistema.o: Sistema.h Sistema.c
	g++ -Wall -c Sistema.c
directorio.o: Directorio.h Directorio.c
	g++ -Wall -c Directorio.c
archivo.o: Archivo.h Archivo.c
	g++ -Wall -c Archivo.c
linea.o: Linea.h Linea.c
	g++ -Wall -c Linea.c
clean:
	rm -f *.o
	rm -f main
