/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:16:33 by tponutha          #+#    #+#             */
/*   Updated: 2022/12/25 05:03:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "builtin.h"

/* This function do
1. print variable
2. shift string's pointer
3. return length of thing it printed
*/

int	ft_vfdprintf(int fd, const char *format, va_list args)
{
	int	len;

	len = 0;
	if (!format)
		return (0);
	while (format[len])
	{
		
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