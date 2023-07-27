#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of buffer
 */
void print_buffer(char *b, int size)
{
	int i, j, k;

	if (size <= 0) /* if size is zero or negative */
	{
		printf("\n"); /* print a new line and return */
		return;
	}
	for (i = 0; i < size; i += 10) /* loop through the buffer, 10 bytes at a time */
	{
		printf("%08x: ", i); /* print the position of the first byte in hexadecimal */
		for (j = i; j < i + 10; j++) /* loop through the next 10 bytes */
		{
			if (j < size) /* if the byte is valid */
				printf("%02x", b[j]); /* print it in hexadecimal */
			else
				printf("  "); /* else print spaces */
			if (j % 2) /* print a space after every two bytes */
				printf(" ");
		}
		for (k = i; k < i + 10; k++) /* loop through the next 10 bytes again */
		{
			if (k >= size) /* if the byte is invalid */
				break; /* stop the loop */
			if (b[k] >= 32 && b[k] <= 126) /* if the byte is printable */
				printf("%c", b[k]); /* print it as a character */
			else
				printf("."); /* else print a dot */
		}
		printf("\n"); /* print a new line after every 10 bytes */
	}
}

