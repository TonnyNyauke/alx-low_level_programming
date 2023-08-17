#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
void print_char(va_list anything, char *separator, int *first);
void print_int(va_list anything, char *separator, int *first);
void print_float(va_list anything, char *separator, int *first);
void print_string(va_list anything, char *separator, int *first);

#endif
