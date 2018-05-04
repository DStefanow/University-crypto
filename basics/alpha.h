#include <stdio.h>
#include <stdlib.h>
#include "core.c"

char ALPHABET[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int LENGTH = sizeof(ALPHABET)/sizeof(char);

int get_method();
int compare_strings(char *str1, char *str2);
int get_arr_position(char symbol);
