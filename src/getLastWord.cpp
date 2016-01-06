/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (!str)
		return NULL;
	int i = -1, lastSpace = -1;
	while (str[++i]) {
		if (str[i] == ' ')
			lastSpace = i;
	}
	char *word = (char *)malloc(sizeof(char)* (i - lastSpace));
	if (word == NULL)
		return NULL;
	int j = 0;
	while (++lastSpace <= i)
		*(word + j++) = *(str + lastSpace);
	return word;
}
