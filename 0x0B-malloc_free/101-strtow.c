#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @str: the string to count
 *
 * Return: the number of words in the string
 */
int word_count(char *str)
{
    int i, wc = 0, in_word = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            in_word = 0;
        else if (in_word == 0)
        {
            in_word = 1;
            wc++;
        }
    }
    return (wc);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, wc, len;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < wc; i++)
	{
		while (str[k] == ' ')
			k++;

		for (j = k, len = 0; str[j] != ' ' && str[j] != '\0'; j++, len++)
			;

		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (j = k; str[j] != ' ' && str[j] != '\0'; j++)
			words[i][j - k] = str[j];
		words[i][j - k] = '\0';

		k += len;
	}
	words[i] = NULL;

	return (words);
}

