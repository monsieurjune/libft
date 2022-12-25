/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:07:25 by tponutha          #+#    #+#             */
/*   Updated: 2022/12/25 07:55:17 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include <stdarg.h>
# include <unistd.h>

// fix printf

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef WEIRD_PRECISION_1
#  define WEIRD_PRECISION_1 2147483648l
# endif

# ifndef WEIRD_PRECISION_2
#  define WEIRD_PRECISION_2 2147483649l
# endif

# ifndef SPECIFIER
#  define SPECIFIER "cspdiuxX%"
# endif

# ifndef PRINTFLAG
#  define PRINTFLAG "-0.# +*"
# endif

/* FLAG -> Type
1.) '-' -> everything
2.) '0' -> everything, can ignore by - .
3.) '.' -> %d, %i, %x , %X as fill 0 | %s as print n charators
	every digits that near . is consider precise, otherwise it is width
4.) '+' -> %d, %i
5.) ' ' -> %d, %i can ignored by +
6.) '#' -> %x %X put 0x || 0X
7.) '*' passing next arg to this as int, can override width but not precise
	and if * is consecutive then last one is legit
*/

typedef struct s_print
{
	char	left;
	char	zero;
	char	sign;
	char	precision;
	char	sharp;
	char	space;
	int		min_width;
	int		precise;
	char	type;
}	t_print;

long			ft_atol_overflow(const char *str);
unsigned long	ft_atoul_overflow(const char *str);

int				ft_isprintflag(char c);
int				ft_isdigit(const char c);

int ft_estimator(const char *format, va_list arg_copy);

#endif