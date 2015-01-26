all: main Makefile

main: bst.o stack.o main.o Makefile
	$(CC)  main.o bst.o stack.o -g -o main

% : %.c Makefile
	$(CC) -c -g $@.c
