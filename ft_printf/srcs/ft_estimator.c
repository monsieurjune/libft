/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_estimator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:21:54 by tponutha          #+#    #+#             */
/*   Updated: 2022/12/25 07:49:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// width should start at num that not zero

int ft_flaglen(const char *format, va_list arg_copy)
{
    int i;
    int minwidth;
    int preslen;
    int flaglen;

    i = 0;
    minwidth = 0;
    preslen = 0;
    flaglen = 1;
    while (ft_isprintflag(format[i]))
    {
        if (format[i] > '0' && format[i] <= '9')
            minwidth = ft_atol_overflow(&format[i]);
        if (format[i] == '.')
        i++;
    }
}

int ft_estimator(const char *format, va_list arg_copy)
{
    int flaglen;
    int i;
    int position;

    i = 0;
    flaglen = 0;
    position = 0;
    while (format[i])
    {
        if (format[i] == '%')
            flaglen = ft_flaglen(format, arg_copy);
        if (flaglen + position < 0)
            return (position);
        i++;
    }
    position = i;
    return (position);
}