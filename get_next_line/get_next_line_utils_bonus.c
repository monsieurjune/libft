/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:05:46 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/29 10:01:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		src = "";
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strncat(char *dst, const char *src, size_t srcsize)
{
	size_t	i;
	size_t	destlen;

	i = 0;
	destlen = ft_strlen(dst);
	if (!src)
		src = "";
	while (src[i] != 0 && i < srcsize)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = 0;
	return (dst);
}
