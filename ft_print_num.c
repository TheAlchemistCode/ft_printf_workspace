
/* LEARN THIS CODE*/

/* ft_print_num:
 * Prints a signed integer 'n' to standard output (fd = 1).
 * Uses ft_itoa to convert the number to a string, then prints it.
 * Returns the number of characters written.
 */
int	ft_print_num(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}