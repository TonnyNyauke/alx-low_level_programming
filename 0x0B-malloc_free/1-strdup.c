#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *dup;
	int len, i;

	if (str == NULL) /* check if str is null */
		return (NULL);

	/* calculate the length of str */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* allocate memory for dup */
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL) /* check if allocation failed */
		return (NULL);

	/* copy str into dup */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
