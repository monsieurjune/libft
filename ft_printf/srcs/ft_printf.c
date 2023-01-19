/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:16:33 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/19 20:14:29 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "builtin.h"

/* This function do
1. print variable
2. shift string's pointer
3. return length of thing it printed
*/

int	ft_printf(const char *format, ...)
{
	int		len;
	int		maxlen;
	va_list	args;
	va_list	args_copy;

	if (!format)
		return (0);
	va_start(args, format);
	va_copy(args_copy, args);
	maxlen = ft_estimator(format, &args_copy);
	va_end(args_copy);
	len = ft_printer(format, args, maxlen);
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
int main()
{
	char *a = "OK BOOMER";
	// char *b = "aerfgmsfdndnfglnzd;dfkmkmlkzmdf";
	ft_printf("%Ec is it shall work?, oh well look 
	at this %u, and this %p -> %s\n", 'a', 7u, a, a);
	return 0;
}
*/