/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:12:01 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/31 15:22:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
