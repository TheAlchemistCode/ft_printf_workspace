/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clyon <clyon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:07:44 by marcela           #+#    #+#             */
/*   Updated: 2025/08/21 21:17:41 by clyon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Here we use recursion, calling itself, to see how many sixteens go into our numb
* number, hex is built by dividing continusly with 16. 
* hex is built on 'remainders' of dividing by 16, from right to left
* len is acting as counter for each "16" to see how many characters will be printed
*/
int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

/* used to display the hex number to the screen*/
void	ft_put_hex(unsigned int num, const char format) // changes num to hex, the format ('x' or 'X', is either lowercase or uppercase)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format); // Print higher digits first (quotient)
		ft_put_hex(num % 16, format); // Then print current digit (remainder)
	}
	else
	{
		if (num <= 9) // we check if (num <= 9) because hexadecimal uses different symbols for different ranges of values:
			ft_putchar_fd((num + 48), 1); // the 1 is for writing to stdout, num+48 because num now is between 1-9, by adding 48 we convert to ascii character '0', '1' etc..
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
