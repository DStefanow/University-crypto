#include<stdio.h>
#include<stdlib.h>

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

	int index;
	for(int i = 0; i < text_length; i++) {
		index = (int)text[i];
	
		if((index >= 65 && index <=90) || (index >= 97 && index <= 122)) {
			printf("|%03d|", index);
		}
		else {
			printf("%c", text[i]);
		}
	}

	return;
}
