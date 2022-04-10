all: generate_matlangc run_matlangc check_compile compile_c run_c


generate_matlangc: main.c string_functions.c
	gcc -o matlangc main.c string_functions.c

run_matlangc: file.mat
	./matlangc file.mat

check_compile:
	ls file.c | xargs echo

compile_c: file.c
	gcc -lm -o prog file.c

run_c: prog
	./prog

