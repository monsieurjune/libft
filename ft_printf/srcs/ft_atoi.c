/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:38:29 by tponutha          #+#    #+#             */
/*   Updated: 2022/12/25 07:11:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// use to handle num's precision + width
// for overflow, precision act like it doesnt has precision
// for width it doesnt print that thing when overint (plus whole format)
// but it act normally again at overlong

// intmax < printed + width

long	ft_atol_overflow(const char *str)
{
	long	sum;

	sum = 0;
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		if (sum < 0)
			sum = (int)sum;
		str++;
	}
	return (sum);
}

// use to handle str's precision

unsigned long	ft_atoul_overflow(const char *str)
{
	unsigned long	sum;

	sum = 0;
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum);
}
