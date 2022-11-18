/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:16:33 by tponutha          #+#    #+#             */
/*   Updated: 2022/11/07 00:17:54 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "builtin.h"

/* This function do
1. print variable
2. shift string's pointer
3. return length of thing it printed
*/

static int	sb_print_argument(int fd, const char **pstr, va_list arg)
{
	t_print	data;

	data = ;
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
		return ();
	return (0);
}

static int	sb_mass_writer(int fd, const char *format, va_list args, int len)
{
	int	len;

	len = 0;
	while (format[len])
	{

	}
}

int	ft_vfdprintf(int fd, const char *format, va_list args)
{
	int	len;

	len = 0;
	if (!format)
		return (0);
	while (format[len])
	{
		`
	}
	return (len);
}

int	ft_fdprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vfdprintf(fd, format, args);
	va_end(args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vfdprintf(1, format, args);
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
int main()
{
	char *a = "OK BOOMER";
	// char *b = "aerfgmsfdndnfglnzd;dfkmkmlkzmdf";
	ft_printf("%c is it shall work?, oh well look at this %u,
	 and this %p -> %s\n", 'a', 7u, a, a);
	return 0;
}
*/