all: compile run

compile: main.c string_functions.c
	gcc -Werror -o matlangc main.c string_functions.c

run: matlangc
	./matlangc test.mat file.c

