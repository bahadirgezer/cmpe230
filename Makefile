all: compile run

compile: main.c string_functions.c
	gcc -Werror -o p main.c string_functions.c

run: p
	./p
