/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:16:33 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/21 00:14:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function do
1. print variable
2. shift string's pointer
3. return length of thing it printed
*/

static int	sb_print_argument(const char **pstr, va_list arg)
{
	char	*alphabet;
	char	type;

	type = (*pstr)[1];
	*pstr += 1 + (type != 0);
	if (type == 's')
		return (ft_put_str(va_arg(arg, const char *)));
	if (type == 'p')
		return (ft_put_ptr(va_arg(arg, unsigned long), "0123456789abcdef"));
	if (type == 'd' || type == 'i')
		return (ft_put_int(va_arg(arg, int)));
	if (type == 'u')
		return (ft_put_uint(va_arg(arg, unsigned int)));
	if (type == 'x' || type == 'X')
		return (ft_put_hex(va_arg(arg, unsigned int), (type == 'x')));
	if (type == '%' || type == 'c')
	{
		alphabet = "%";
		if (type == 'c')
			alphabet = va_arg(arg, char *);
		write(1, alphabet, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	va_start(args, format);
	if (format)
	{
		while (*format)
		{
			if (*format == '%')
			{
				len += sb_print_argument(&format, args);
				continue ;
			}
			write(1, format, 1);
			len++;
			format++;
		}
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
int main()
{
	char *a = "OK BOOMER";
	// char *b = "aerfgmsfdndnfglnzd;dfkmkmlkzmdf";
	ft_printf("%c is it shall work?, oh well look at this %u, and this %p -> %s\n", 'a', 7u, a, a);
	return 0;
}
*/