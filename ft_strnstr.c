/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:38:59 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 22:38:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	sub_check(const char *str, const char *find, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (find[j] && i + j < n)
	{
		if (str[i + j] != find[j])
			return (0);
		j++;
	}
	return (find[j] == 0);
}

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;

	if (!find || !find[0])
		return ((char *)str);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == find[0])
			if (sub_check(str, find, i, n))
				return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
