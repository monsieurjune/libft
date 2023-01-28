/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:39:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 21:25:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	sb_getmax(int *array, size_t size)
{
	size_t	i;
	int		max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

static int	*sb_countsort(int *array, size_t size, int power, t_listmem **head)
{
	int	i;
	int	bucket[256];
	int	*output;

	i = 0;
	if ()
	ft_memset(bucket, 0, 256);
	while (i < size)
	{
		bucket[(array[i] / power) % 10]++;
		i++;
	}
	i = 1;
	while (i < 256)
	{
		bucket[i] += bucket[i - 1];
		i++;
	}

}

int	*ft_radixsort_array(int *array, size_t size, t_listmem **head)
{
	int	power;
	int	max;

	max = sb_getmax(array, size);
	power = 1;
	while (max / power > 128)
	{
		array = 
		power *= 128;
	}
}

static int	sb_isduplicate(int ac, int *res)
{
	
}