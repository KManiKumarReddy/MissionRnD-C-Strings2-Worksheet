/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>


void count_vowels_and_consonants(char *str, int *consonants, int *vowels) {
	*consonants = *vowels = 0;
	if (!str)
		return;
	int i = 0, c;
	while (c = str[i]) {
		if (c >= 65 && c <= 90) {
			if (c == 65 || c == 69 || c == 73 || c == 79 || c == 85)
				(*vowels)++;
			else
				(*consonants)++;
		}
		else if (c >= 97 && c <= 122) {
			if (c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
				(*vowels)++;
			else
				(*consonants)++;
		}
		i++;
	}
}
