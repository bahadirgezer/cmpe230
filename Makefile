all: compile generate run

compile: main.c string_functions.c
	gcc -Werror -o matlangc main.c string_functions.c

generate: 
	touch file.c

run: matlangc
	./matlangc test.mat file.c
