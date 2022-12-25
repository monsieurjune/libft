/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 06:57:31 by tponutha          #+#    #+#             */
/*   Updated: 2022/12/25 07:10:00 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_isdigit(const char c)
{
    return (c >= '0' && c <= '9');
}

int ft_isprintflag(const char c)
{
    int i;

    i = 0;
    while (PRINTFLAG[i])
    {
        if (c == PRINTFLAG[i] || ft_isdigit(c))
            return (TRUE);
        i++;
    }
    return (FALSE);
}