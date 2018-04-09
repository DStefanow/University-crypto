#include "alpha.h"

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
		printf("Enter a positive number key for start index: ");
		scanf("%d", &key);

		if (key > 0) {
			break;
		}

		clear_stdin();
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

