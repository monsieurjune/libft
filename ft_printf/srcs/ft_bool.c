/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 06:57:31 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/19 20:35:55 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_isdigit(const char c)
{
    return (c >= '0' && c <= '9');
}

int ft_isprint_flag(const char c)
{
    int i;

    i = 0;
    while (PRINTFLAG[i])
    {
        if (c == PRINTFLAG[i])
            return (TRUE);
        i++;
    }
    return (FALSE);
}

int ft_isprint_item(const char c)
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