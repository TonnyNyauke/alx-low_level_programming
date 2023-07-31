#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to search for
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *p, *startn = needle;

	while (*haystack)
	{
		startn = needle;
		p = haystack;
		while (*haystack && *startn && *haystack == *startn)
		{
			haystack++;
			startn++;
		}
		if (!*startn)
			return (p);
		haystack = p + 1;
	}
	return (0);
}

