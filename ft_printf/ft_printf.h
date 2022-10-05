/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:14:52 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/16 08:49:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_put_str(const char *str);
int	ft_put_ptr(unsigned long ptr, char *base);
int	ft_put_int(int n);
int	ft_put_uint(unsigned int un);
int	ft_put_hex(unsigned int hex, char islower);
int ft_put_char(char c);

#endif
