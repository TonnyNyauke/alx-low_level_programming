#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: actual arguments to be printed
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str;
	va_list list;

	va_start(list, format);

	while (format && format[i])
	{
		if (i > 0 && (format[i - 1] == 'c' || format[i - 1] == 'i'
		|| format[i - 1] == 'f' || format[i - 1] == 's'))
			printf(", ");

		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(list, int));
				break;
			case 'i':
				printf("%d", va_arg(list, int));
				break;
			case 'f':
				printf("%f", va_arg(list, double));
				break;
			case 's':
				str = va_arg(list, char *);
				if (!str)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				break;
		}

		i++;
	}

	printf("\n");
	va_end(list);
}

