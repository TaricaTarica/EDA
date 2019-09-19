todo: main.o gestor.o
	g++ -Wall -o main main.o gestor.o
main.o: main.c
	g++ -Wall -c main.c
gestor.o: gestor.c gestor.h
	g++ -Wall -c gestor.c
clean:
	rm -f *.o
	rm -f main
