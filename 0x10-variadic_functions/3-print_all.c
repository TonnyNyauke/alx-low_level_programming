#include "variadic_functions.h"

/**
 * print_char - prints a char
 * @anything: va_list of arguments
 * @separator: separator string
 * @first: pointer to first flag
 *
 * Return: void
 */
void print_char(va_list anything, char *separator, int *first)
{
	if (!(*first))
		printf("%s", separator);
	printf("%c", va_arg(anything, int));
	*first = 0;
}

/**
 * print_int - prints an int
 * @anything: va_list of arguments
 * @separator: separator string
 * @first: pointer to first flag
 *
 * Return: void
 */
void print_int(va_list anything, char *separator, int *first)
{
	if (!(*first))
		printf("%s", separator);
	printf("%d", va_arg(anything, int));
	*first = 0;
}

/**
 * print_float - prints a float
 * @anything: va_list of arguments
 * @separator: separator string
 * @first: pointer to first flag
 *
 * Return: void
 */
void print_float(va_list anything, char *separator, int *first)
{
	if (!(*first))
		printf("%s", separator);
	printf("%f", va_arg(anything, double));
	*first = 0;
}

/**
 * print_string - prints a string
 * @anything: va_list of arguments
 * @separator: separator string
 * @first: pointer to first flag
 *
 * Return: void
 */
void print_string(va_list anything, char *separator, int *first)
{
	if (!(*first))
		printf("%s", separator);
	char *string = va_arg(anything, char *);

	if (string == NULL)
		string = "(nil)";
	printf("%s", string);
	*first = 0;
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list anything;
	unsigned int i = 0;
	char str;
	char *separator = ", ";
	int first = 1;

	va_start(anything, format);

	while (format && format[i])
	{
		str = format[i];
		switch (str)
		{
			case 'c':
				print_char(anything, separator, &first);
				break;
			case 'i':
				print_int(anything, separator, &first);
				break;
			case 'f':
				print_float(anything, separator, &first);
				break;
			case 's':
				print_string(anything, separator, &first);
				break;
			default:
				i++;
				continue;
		}
		i++;
	}
	printf("\n");
	va_end(anything);
}

