all: s21_cat

s21_cat: 
	gcc -Wall -Wextra -Werror -D_GNU_SOURCE stack.h s21_cat.c -o s21_cat

clean: 
	rm -rf s21_cat
	
rebuild: clean s21_cat
