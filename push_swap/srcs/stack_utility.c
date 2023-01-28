/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:54:54 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 17:37:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*ft_memset(void *ptr, int c, size_t byte)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < byte)
	{
		((unsigned char *)ptr)[i] = ((unsigned char *)&c)[0];
		i++;
	}
	return (ptr);
}

void	ft_exit(t_listmem **head)
{
	lm_flush(head);
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}