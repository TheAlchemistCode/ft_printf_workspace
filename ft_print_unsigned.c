/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Q <Q@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:09:41 by marcela           #+#    #+#             */
/*   Updated: 2025/08/29 17:26:03 by Q                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/*
 * ft_uitoa:
 * Converts an unsigned int 'n' into a string representation (base 10).
 * Returns a pointer to a malloc'd string containing the number as characters.
 * Caller is responsible for freeing the allocated memory.
 * 
 *  this pointer, *num, is used to hold the string result (ascii)
 *  len is the number of characters needed to print the string
 *  in the loop,  %10 is to get the digit at the end (right side)
 *  +48 converts to ascii,
 *  n / 10 is to remove the last digit, len -- to move left in the string
 */
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

/*
 * ft_print_unsigned:
 * Prints an unsigned integer 'n' to standard output (fd = 1).
 * Uses ft_uitoa to convert the number to a string, then prints it.
 * Returns the number of characters written.
 */
int	ft_print_unsigned(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		length += ft_print_str(num);
		free(num);
	}
	return (length);
}

