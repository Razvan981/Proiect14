all: exe

exe: main.o TopSort1.o TopSort2.o 
	gcc main.o TopSort1.o TopSort2.o -o exe

main.o: main.c
	gcc -c main.c

TopSort1.o: TopSort1.c
	gcc -c TopSort1.c

TopSort2.o: TopSort2.c
	gcc -c TopSort2.c
	
clean:
	rm *.o exe
