#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to concatenate from s2
 *
 * Return: pointer to the concatenated string, or NULL if failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s; /* New string */
	unsigned int i, j, len1, len2;

	/* check if s1 or s2 are NULL and treat them as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* get the lengths of s1 and s2 */
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	/* if n is greater or equal to the length of s2, use the entire s2 */
	if (n >= len2)
		n = len2;

	/* allocate memory for the concatenated string */
	s = malloc(sizeof(char) * (len1 + n + 1));
	if (s == NULL)
		return (NULL);

	/* copy s1 into s */
	for (i = 0; i < len1; i++)
		s[i] = s1[i];

	/* copy n bytes of s2 into s */
	for (j = 0; j < n; j++)
		s[i + j] = s2[j];

	/* add the null terminator */
	s[i + j] = '\0';

	return (s);
}

