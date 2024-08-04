all: s21_grep

s21_grep: 
	gcc -Wall -Wextra -Werror -D_GNU_SOURCE stack.h s21_grep.c -o s21_grep

clean: 
	rm -rf s21_grep
	
rebuild: clean s21_grep
