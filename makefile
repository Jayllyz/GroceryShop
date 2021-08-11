all: PROJET EXCUTION
PROJET: main.c  
	gcc -o EXEC main.o 
EXCUTION: EXEC
	./EXEC
