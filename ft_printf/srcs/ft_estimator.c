/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estimator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:04:44 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/19 20:48:21 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	sb_minlen()

int	sb_precision()

int sb_etcflag()

int	sb_flagsize(const char *format, va_list *arg_copy, int *ii)
{
	t_print temp;
	int		j;

	j = 0;
	while (ft_isprint_item(format[j]))
	{
		if (format[j] > '0' && format[j] <= '9')
			djgj
		if (format[j] == '.')
			hnfgdk
		if (format[j] == '+' || format[j] == '')
			jfkjd
		j++;
	}
	return ()
}

int	ft_estimator(const char *format, va_list *arg_copy)
{
	int	pos;
	int	i;
	int	flagsize;

	i = 0;
	pos = 0;
	while (format[i])
	{
		if (format[i] == '%')
			flagsize = sb_flagsize(&format[i], arg_copy, &i);
		if (pos + flagsize < 0)
			return (pos);
		pos = i;
		i++;
	}
	return (i);
}