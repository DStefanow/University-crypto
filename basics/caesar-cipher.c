#include<ctype.h>
#include <string.h>
#include "alpha.h"

int get_arr_position(char symbol);
int get_method();
int compare_strings(char *str1, char *str2);

void get_user_data();
void encrypt_data();
void decrypt_data();

char *text;
int key;
size_t text_length;
size_t text_max_size = 1024;

void main()
{
	int method_num;

	// Get method type: 1 for encrypt and 2 for decrypt
	method_num = get_method();

	// Read the text and the key number
	get_user_data();

	if (method_num == 1) {
		encrypt_data();
	}
	else if (method_num == 2) {
		decrypt_data();
	}

	return;
}

void get_user_data() {
	// Read the text
	text = (char*)malloc(text_max_size * sizeof(char));
	while (1) {
		printf("Enter text: ");
		text_length = getline(&text, &text_max_size, stdin);

		if (text_length > 1) {
			break;
		}
	}

	// Read key number
	while (1) {
		printf("Enter a positive number key: ");
		scanf("%d", &key);

		if (key > 0) {
			break;
		}
	}

	return;
}

void encrypt_data() {
	// Start encryption and print the encrypted data
	int i = 0;
	int new_index;
	int alphabet_position;

	printf("Encrypted data: ");
	while (1) {
		// end of the string
		if (i == text_length) {
			break;
		}

		// Print encrypted symbol or print the symbol from the string, that is not letter - begin
		alphabet_position = get_arr_position(text[i]);

		if (alphabet_position > -1) {
			new_index = (alphabet_position + key) % LENGTH;
			printf("%c", ALPHABET[new_index]);
		}
		else {
			printf("%c", text[i]);
		}
		// Print encrypted symbol or print the symbol from the string, that is not letter - begin

		i++;
	}
	printf("\n");
}

void decrypt_data() {
	int i = 0;
	int new_index;
	int alphabet_position;

	printf("Decrypted data: ");
	while (1) {
		// end of the string
		if (i == text_length) {
			break;
		}

		alphabet_position = get_arr_position(text[i]);

		if (alphabet_position > -1 ) {
			new_index = (alphabet_position - key) % LENGTH;

			if (new_index < 0) {
				new_index = LENGTH + new_index;
			}

			printf("%c", ALPHABET[new_index]);
		}
		else {
			printf("%c", text[i]);
		}

		i++;
	}

	printf("\n");
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

