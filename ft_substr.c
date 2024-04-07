/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:27:00 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 15:46:07 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*d;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = (size_t)start;
	if (i > slen)
		return (ft_calloc(1, sizeof(char)));
	if (len + i > slen)
		len = slen - i;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	(void)ft_strlcpy(d, &s[i], len + 1);
	return (d);
}
