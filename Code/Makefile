# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
# -c = compilation
# -Wall = throws all warnings
CFLAGS=-c -Wall

all: exe

exe: main.o TopSort1.o TopSort2.o
	$(CC) main.o TopSort1.o TopSort2.o -o exe

main.o: main.c
	$(CC) $(CFLAGS) main.c

TopSort2.o: TopSort2.c
	$(CC) $(CFLAGS) TopSort2.c

TopSort1.o: TopSort1.c
	$(CC) $(CFLAGS) TopSort1.c

clean:
	rm *o exe
