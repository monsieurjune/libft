/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:01:38 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 00:20:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t byte)
{
	size_t	i;
	size_t	diff;

	if (!dst || !src || !byte)
		return (dst);
	i = (byte - 1) * (dst > src);
	diff = 1;
	if (dst > src)
		diff = -1;
	while (i < byte)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += diff;
		if (i == 0)
		{
			((unsigned char *)dst)[0] = ((unsigned char *)src)[0];
			break ;
		}
	}
	return (dst);
}
