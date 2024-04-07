/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:42:22 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/08 14:54:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || size < 1 || !src)
		return (srclen);
	i = 0;
	if (size > srclen + 1)
		size = srclen + 1;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[size - 1] = 0;
	return (srclen);
}
