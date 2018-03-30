#include "alpha.h"

/**
-------ALPHABET MATRIX FOR THE EXAMPLE-------
		  0 1 2 3 4
		0 a b c d e
		1 f g h i j
		2 k l m n o
		3 p q r s t
		4 o v w x y
		5 z - - - -
- Are blank spaces
*/


#define COLS 5

void get_user_data_for_encrypt();
void get_user_data_for_decrypt();
void encrypt_data();
void decrypt_data();

char *text;
int text_length;
size_t text_max_size = 1024;

void main()
{
	int method_num;

	// Get method type: 1 for encrypt and 2 for decrypt
	method_num = get_method();

	if (method_num == 1) {
		get_user_data_for_encrypt();
		encrypt_data();
	}
	else if (method_num == 2) {
		get_user_data_for_decrypt();
		decrypt_data();
	}

	return;
}

void get_user_data_for_encrypt() {
	int i;
	char isValid = 1;

	// Read the text
	text = (char*)malloc(text_max_size * sizeof(char));
	while (1) {
		printf("Enter text (clear text, no numbers, special characters and white spaces): ");
		text_length = getline(&text, &text_max_size, stdin);

		isValid=1;
		for (i = 0; i < text_length - 1; i++) {
			if (get_arr_position(text[i]) == -1) {
				isValid = 0;
				break;
			}
		}

		if ((text_length > 1) && (isValid == 1)) {
			break;
		}
	}

	return;
}

void get_user_data_for_decrypt() {
	int i;
	char isValid = 1;

	// Read the text
	text = (char*)malloc(text_max_size * sizeof(char));
	while (1) {
		printf("Enter text (clear text with even length, that contains only digits between 0 and 4 for column and 0 and 5 for row): ");
		text_length = getline(&text, &text_max_size, stdin) - 1;

		isValid=1;

		// We can decrypt only text with even length
		if (text_length % 2 != 0) {
			printf("Invalid input data!\n");
			continue;
		}

		for (i = 0; i < text_length - 1; i+=2) {
			// Check first and second digit
			if ((text[i] < '0' || text[i] > '5') || (text[i + 1] < '0' || text[i + 1] > '4')) {
				printf("Invalid input data!\n");
				// Invalid character
				isValid=0;
				break;
			}

		}

		if ((text_length > 1) && (isValid == 1)) {
			break;
		}
	}
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
			int row = alphabet_position / COLS;
			int col = alphabet_position % COLS;
			printf("%d%d", row , col);
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

	int row,col;

	printf("Decrypted data: ");
	while (1) {
		// end of the string
		if (i ==  text_length) {
			break;
		}

		row = (int)text[i] - 48;
		col = (int)text[i + 1] - 48;

		printf("%c", ALPHABET[(row * COLS) + col]);

		i+=2;
	}

	printf("\n");
}

