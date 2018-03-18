#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alpha.h"

int get_arr_position(char symbol);

void main()
{
	char *text;
	size_t key;
	size_t text_length;
	size_t text_max_size = 1024;

	// Read the text - begin
	text = (char*)malloc(text_max_size * sizeof(char));
	while (1) {
		printf("Enter text: ");
		text_length = getline(&text, &text_max_size, stdin);

		if (text_length > 1) {
			break;
		}
	}
	// Read the text - end

	// Read key number - start
	while (1) {
		printf("Enter a positive number key: ");
		scanf("%zu", &key);

		if (key > 0) {
			break;
		}
	}
	// Read key number - end

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

	return;
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

