/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:38:29 by tponutha          #+#    #+#             */
/*   Updated: 2022/11/06 19:13:48 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// use to handle num's precision + width
// for overflow precision act like it doesnt exist
// for width it doesnt print that thing when overint
// but it act normally again at overlong

long	ft_atol_overflow(const char *str)
{
	long	sum;

	sum = 0;
	while (*str >= '0' && *str <= '9')
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
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum);
}