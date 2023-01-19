/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:07:25 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/19 20:46:18 by tponutha         ###   ########.fr       */
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

# ifndef SPECIFIER
#  define SPECIFIER "cspdiuxX%"
# endif

# ifndef PRINTFLAG
#  define PRINTFLAG "-0.# +*"
# endif

/* FLAG -> Type
1.) '-' -> put minwidth at right, everything
2.) '0' -> replace ' ' with 0, everything, can ignore by - .
3.) '.' -> %d, %i, %x , %X as fill 0 | %s as print n charators
	every digits that near . is consider precise, otherwise it is width
4.) '+' -> %d, %i
5.) ' ' -> %d, %i can ignored by +
6.) '#' -> %x %X put 0x || 0X
7.) '*' passing next arg to this as int, can override width but not precise
	and if * is consecutive then last one is legit
8.) NOTE that recent width and precise is legit,
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

int 			ft_isprint_flag(const char c);
int				ft_isprint_item(const char c);
int				ft_isdigit(const char c);

int 			ft_estimator(const char *format, va_list *arg_copy);

int				ft_printer(const char *format, va_list *args, int maxlen);

#endif