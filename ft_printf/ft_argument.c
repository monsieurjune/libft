/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:20:12 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/21 00:07:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_put_ptr(unsigned long ptr, char *base)
{
	int	len;

	len = 1;
	if (ptr >= 16)
		len += ft_put_ptr(ptr / 16, base);
	write(1, &base[ptr % 16], 1);
	return (len);
}

int	ft_put_uint(unsigned int un)
{
	int	len;

	len = 1;
	if (un >= 10)
		len += ft_put_int(un / 10);
	write(1, &"0123456789"[un % 10], 1);
	return (len);
}

int	ft_put_int(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
		n *= -1;
	return (ft_put_uint(n));
}

int	ft_put_hex(unsigned int hex, char islower)
{
	char	*base;

	if (islower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_put_ptr(hex, base));
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	unsigned long a = atol(av[1]);
	printf("%d\n", ft_put_ptr(a));
	return (0);
}
*/