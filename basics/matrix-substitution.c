#include <stdio.h>
#include <stdlib.h>
#include "alpha.h"

// Declare used methods and variables
size_t TEXT_MAX_SIZE = 1024;

void get_user_data();
void encrypt_data();
void decrypt_data();

char *text;
char * key;
size_t text_length;
size_t key_length;

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
	text = (char*)malloc(TEXT_MAX_SIZE * sizeof(char));
	while (1) {
		// Read text and remove '\n' on the end
		printf("Enter text: ");
		text_length = getline(&text, &TEXT_MAX_SIZE, stdin) - 1;

		if (text_length > 0) {
			break;
		}
	}

	size_t i = 0;
	char isInvalid = 0;
	key = (char*)malloc(TEXT_MAX_SIZE * sizeof(char));
	// Read key number
	while (1) {
		isInvalid = 0;

		// Read key and remove '\n' on the end
		printf("Enter key cipher (Only valid elements): ");
		key_length = getline(&key, &TEXT_MAX_SIZE, stdin) - 1;

		// Check if key contains invalid symbols
		while (i < key_length) {
			if (get_arr_position(key[i]) == -1) {
				printf("Use only elements from declared alphabet.\n");
				isInvalid = 1;
				break;
			}

			i++;
		}

		if ((key_length > 0) && (isInvalid == 0)) {
			break;
		}
	}

	return;
}

void encrypt_data() {
	// Start encryption and print the encrypted data
	int i = 0, j = 0;
	int new_index;
	int text_element_position;
	int key_position;

	printf("Encrypted data: ");
	while (1) {
		// end of the string
		if (i == text_length) {
			break;
		}

		// Print encrypted symbol or print the symbol from the string, that is not letter - begin
		text_element_position = get_arr_position(text[i]);
		key_position = get_arr_position(key[j % key_length]);

		if ((text_element_position > -1) && (key_position > -1)) {
			new_index = (text_element_position + key_position) % LENGTH;
			printf("%c", ALPHABET[new_index]);

			// Use `j` instead of `i` because we can have symbols that are not in the defined ALPHABET
			j++;
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
	int i = 0, j = 0;
	int new_index;
	int text_element_position;
	int key_position;

	printf("Decrypted data: ");
	while (1) {
		// end of the string
		if (i == text_length) {
			break;
		}

		text_element_position = get_arr_position(text[i]);
		key_position = get_arr_position(key[j % key_length]);

		if ((text_element_position > -1) && (key_position > -1)) {
			new_index = (text_element_position - key_position) % LENGTH;

			if (new_index < 0) {
				new_index = LENGTH + new_index;
			}

			printf("%c", ALPHABET[new_index]);

			// Use `j` instead of `i` because we can have symbols that are not in the defined ALPHABET
			j++;
		}
		else {
			printf("%c", text[i]);
		}

		i++;
	}

	printf("\n");
}
