/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:30:53 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 20:25:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newc)
{
	t_list	*head;

	if (*lst)
	{
		head = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = newc;
		*lst = head;
	}
	else
		*lst = newc;
}
