#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * print_all - print anything
 * @format: a list of types of arguments
 */

void print_all(const char * const format, ...)
{
	va_list va;
	char c, *s, *fmt, *sep = ", ";
	float f;
	int i, count = 0, state = 1;

	if (!format)
	{
		fmt = strdup("");
		state = 0;
	}
	else fmt = strdup(format);
	va_start(va, format);

	while (*fmt)
	{
		if (!format[count + 1])
			sep = "";
		switch (*fmt++)
		{
			case 'c':
				c = (char) va_arg(va, int);
				printf("%c%s", c, sep);
				break;
			case 'i':
				i = va_arg(va, int);
				printf("%i%s", i, sep);
				break;
			case 'f':
				f = (float) va_arg(va, double);
				printf("%f%s", f, sep);
				break;
			case 's':
				s = va_arg(va, char *);
				if (!s)
					s = "(nil)";
				printf("%s%s", s, sep);
				break;
			default:
				break;
		}
		count++;
	}
	if (state == 1)
		printf("\n");
	va_end(va);
}

