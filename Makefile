all: compile generate run

compile: main.c string_functions.c
	gcc -Werror -ferror-limit=200 -o matlangc main.c string_functions.c

generate: 
	touch file.c

run: matlangc
	./matlangc test.mat file.c
