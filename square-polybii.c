#include<stdio.h>
#include<stdlib.h>
#include <ctype.h> 

#define LENGTH 6

char ALPHABET[LENGTH][LENGTH] = {
	{ 'a','b','c','d','e','f' },
	{ 'g','h','i','j','k','l' },
	{ 'm','n','o','p','q','r' },
	{ 's','t','u','v','w','x' },
	{ 'y','z','.','!','?',',' }
};

void main()
{
	char *text;
  size_t text_max_size = 1024;
  size_t text_length;

  // Read the text - begin
  text = (char*)malloc(text_max_size * sizeof(char));
  printf("Enter text: ");
  text_length = getline(&text, &text_max_size, stdin);
  // Read the text - end
	
	for (int m = 0; m < text_length; m++) {
		char symbol = text[m];
		
		for (int i = 0; i < LENGTH; i++) {
			for (int j = 0; j < LENGTH; j++) {
				if (tolower(symbol) == ALPHABET[i][j]) {
					printf("{%d %d}", i, j);
					break;
				}
			}
		}
	}
	printf("\n");

	return;
}
