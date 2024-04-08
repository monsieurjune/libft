/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:10:49 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 01:56:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// MEMORY MANIPULATE FUNCTION
void	*ft_memset(void *ptr, int c, size_t byte);
void	*ft_bzero(void *ptr, size_t byte);
void	*ft_memcpy(void *dst, const void *src, size_t byte);
void	*ft_memmove(void *dst, const void *src, size_t byte);
void	*ft_memchr(const void *ptr, int c, size_t byte);
int		ft_memcmp(const void *p1, const void *p2, size_t n);

// NON-ALLOCATED STRING FUNCTION
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *find, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

// CHARACTER CONDITION CHECKING FUNCTION 
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// MEMMORY ALLOCATING FUNCTION
void	*ft_calloc(size_t byte, size_t size);

// ALLOCATED STRING FUNCTION
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// FILE-DESCRIPTOR WRITING FUNCTION
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// SINGLE LINKED-LIST FUNCTION
// ALLOCATE LINKED-LIST FUNCTION
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// DEALLOCATE LINKED-LIST FUNCTION
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

// GET NODE FUNCTION
t_list	*ft_lstlast(t_list *lst);

// ADD NODE TO LIST FUNCTION
void	ft_lstadd_front(t_list **lst, t_list *newc);
void	ft_lstadd_back(t_list **lst, t_list *newc);

// MANIPULATING FUNCTION
void	ft_lstiter(t_list *lst, void (*f)(void *));

// GET LINKED-LIST'S SIZE FUNCTION
int		ft_lstsize(t_list *lst);

#endif
