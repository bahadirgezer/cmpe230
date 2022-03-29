all: compile run

compile: main.c string_functions.c
	gcc -Werror -ferror-limit=200 -o matlangc main.c string_functions.c

run: matlangc
	./matlangc
