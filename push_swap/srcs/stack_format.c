/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:32:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 21:25:47 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
BIG NONO
1.) overflow
2.) non-int format
3.) dupicate
*/

static long sb_atol(char *str)
{
	int		i;
	long	neg;
	long	sum;

	i = 0;
	sum = 0;
	neg = 1;
	if (*str == '-')
		neg = -1;
	str += (*str == '+' || *str == '-');
	while (str[i] >= '0' && str[i] <= '9' && i <= 10)
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sum > 2147483648)
		return (INT64_MAX);
	return (neg * sum);
}

static int	sb_check_format(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (FALSE);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] > '0' && str[i] <= '9'))
		return (FALSE);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (str[i - 1] >= '0' && str[i - 1] <= '9');
}

int	*ft_atoi_array(int ac, char **av, t_listmem **head)
{
	long	temp;
	int		*res;
	int		i;
	int		j;

	i = 1;
	res = lm_malloc(sizeof(int), ac - 1, head);
	if (res == NULL)
		return (NULL);
	while (i < ac)
	{
		if (!sb_check_format(av[i]))
			return (NULL);
		temp = sb_atol(av[i]);
		if (temp == INT64_MAX)
			return (NULL);
		res[i - 1] = (int)temp;
		i++;
	}
	return (res);
}