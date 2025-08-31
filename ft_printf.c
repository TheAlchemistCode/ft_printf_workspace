


#include "ft_printf.h"

/* 
 * Handles a single format specifier (like %c, %s, %d, etc.) and prints the
 * corresponding argument from the variable argument list.
 * 
 * - va_list args: "Here’s my cursor. It exists, but it’s not pointing anywhere yet.”
 * - va_start (args, str): "Now, I’m pointing at the first argument after str.”
 * 
 * - Give me whatever the cursor is pointing at, interpret it as type, 
 * and then move forward to the next argument.”
 * 
 * va_end (args): "I’m done with the arguments. put the cursor away.”
 * 
 * format parameter is a format specifier character (like 'c', 's', 'd', etc.)
 * 
 * c = character (ascii)
 * s = string
 * p = pointer (address in memory)
 * d = decimal
 * u = unsigned decimal
 * x = hexadecimal (lowercase)
 * 
*/ 

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_chr(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_num(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_chr('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	va_list		args;
	int			length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_format(args, str[i + 1]);
			i++;
		}
		else
			length += ft_print_chr(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
