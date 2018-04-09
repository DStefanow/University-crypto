#include<stdio.h>
#include<stdlib.h>
#include "alpha.h"

void get_user_data_for_encrypt();
void get_user_data_for_decrypt();
void encrypt_data();
void decrypt_data();

char *text;
int text_length;
size_t text_max_size = 1024;
int key_index;

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

	// Read key number
	while (1) {
		printf("Enter a positive number key for start index: ");
		scanf("%d", &key_index);

		if (key_index > 0) {
			break;
		}
	}

	return;
}

void get_user_data_for_decrypt()
{
	// TODO ...
}

void encrypt_data()
{
	// TODO ...
}

void decrypt_data()
{
	// TODO ...
}
