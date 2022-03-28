all: compile run

compile: main.c string_functions.c
	gcc -o p main.c string_functions.c

run: p
	./p
