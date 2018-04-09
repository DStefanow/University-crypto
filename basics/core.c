#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

char ALPHABET[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int LENGTH = sizeof(ALPHABET)/sizeof(char);

// Clear buffer until end of line
int clear_stdin() {
	while(getchar() != '\n');
	return 1;
}

int compare_strings(char *str1, char *str2) {
	size_t i = 0;
	size_t len_str1 = strlen(str1) - 1;
	size_t len_str2 = strlen(str2);
	size_t max_length = len_str1 > len_str2 ? len_str1 : len_str2; // Remove '\n' on the end of the string

	// Empty string
	if (len_str1 == 0) {
		return 0;
	}

	while (i < max_length) {
		if (str1[i] != str2[i]) {
			return 0;
		}

		i++;
	}

	return 1;
}

/**
* Get method type:
* 1 - for encrypt
* 2 - for decrypt
*/
int get_method() {
	char *method;
	size_t method_max_length = 16;
	size_t method_length;

	method = (char*)malloc(method_max_length * sizeof(char));
	// Read the type of the method (encrypt/decrypt)
	while (1) {
		printf("Enter method (encrypt/decrypt): ");
		method_length = getline(&method, &method_max_length, stdin);

		if (compare_strings(method,"encrypt")) {
			return 1;
		}

		else if (compare_strings(method, "decrypt")) {
			return 2;
		}
	}

	return 0;
}

/**
	Check if given symbol is in the ALPHABET array
*/
int get_arr_position(char symbol) {
	for(int i = 0; i < LENGTH; i++) {
		if( tolower(symbol) == ALPHABET[i]) {
			return i;
		}
	}

	return -1;
}

