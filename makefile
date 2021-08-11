all: PROJET EXCUTION
PROJET: main.c  
	gcc -c -Wall main.c -Werror
EXCUTION: EXEC
	./EXEC
