#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest(char array[]);

int main(int argc, char* argv[])
{
	longest(argv[1]);

	return(0);
}

int longest(char array[])
{
	char words[50][50];
	int word_count = 0;
	int char_count = 0;
	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] == ' ') 
		{
			words[word_count][char_count] = '\0';
			word_count++;
			char_count = 0;
			continue;
		}
		words[word_count][char_count] = array[i];
		char_count++;
	}
	words[word_count][char_count] = '\0';

	int longest_i = 0;
	for (int i = 1; i < word_count + 1; i++)
	{
		if (strlen(words[longest_i]) < strlen(words[i]))
		{
			longest_i = i;
		}
	}

	printf("%s\n", words[longest_i]);
	return 0;
}
