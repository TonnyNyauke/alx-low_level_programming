#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	int len1, len2, i, j;

	/* check if s1 or s2 are null */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* calculate the lengths of s1 and s2 */
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	/* allocate memory for s */
	s = malloc((len1 + len2 + 1) * sizeof(char));
	if (s == NULL) /* check if allocation failed */
		return (NULL);

	/* copy s1 into s */
	for (i = 0; i < len1; i++)
		s[i] = s1[i];

	/* copy s2 into s after s1 */
	for (j = 0; j < len2; j++)
		s[i + j] = s2[j];

	/* add null character at the end of s */
	s[i + j] = '\0';

	return (s);
}

