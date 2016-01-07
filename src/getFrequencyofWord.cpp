/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int strlen(char *str) {
	if (!str)
		return 0;
	int i = 0;
	while (str[i]) i ++;
	return i;
}

void computeLPSArray(char *sub, int M, int *lps) {
	int prevLong = 0;
	lps[0] = 0;
	int i = 1;

	while (i < M) {
		if (sub[i] == sub[prevLong]) {
			prevLong++;
			lps[i] = prevLong;
			i++;
		}
		else if (prevLong != 0)
			prevLong = lps[prevLong - 1];
		else {
			lps[i] = 0;
			i++;
		}
	}
}

int count_word_in_str_way_1(char *str, char *word){
	if (!str || !word || !(*word) || !(*str))
		return 0;
	// using KMP pattern matching
	int M = strlen(word);
	int N = strlen(str);

	//calculating longest prefix of suffixes
	int *lps = (int *)malloc(sizeof(int)*M);
	computeLPSArray(word, M, lps);

	int i = 0, j = 0, count = 0;
	while (i < N) {
		if (word[j] == str[i]) {
			j++;
			i++;
		}
		// if word found
		if (j == M) {
			count++;
			j = lps[j - 1];
		} 
		else if (i < N && word[j] != str[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	free(lps);
	return count;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	if (!str || !word || !(*word) || !(*str))
		return 0;
	int i = 0;
	while (*(str + i)) {
		if (!*(word + i))
			return 1 + count_word_int_str_way_2_recursion(++str, word);
		else if (*(word + i) == *(str + i))
			i++;
		else
			return count_word_int_str_way_2_recursion(++str, word);
	}
	return *(word + i) ? 0 : 1;
}