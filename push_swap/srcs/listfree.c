/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:23:44 by tponutha          #+#    #+#             */
/*   Updated: 2023/01/28 21:29:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listmem.h"

static void	lm_free_node(t_listmem *node)
{
	free(node->mem);
	free(node);
}

void	lm_free(void *byte, t_listmem **head)
{
	t_listmem	*runner;
	t_listmem	*prev;

	prev = NULL;
	runner = *head;
	while (runner != NULL)
	{
		if (runner->mem == byte && prev == NULL)
		{
			*head = (*head)->next;
			lm_free_node(runner);
			return ;
		}
		else if (runner->mem == byte && prev != NULL)
		{
			prev->next = runner->next;
			lm_free_node(runner);
			return ;
		}
		prev = runner;
		runner = runner->next;
	}
}

void	lm_flush(t_listmem **head)
{
	t_listmem	*front;

	if (*head == NULL )
		return ;
	while (*head != NULL)
	{
		front = (*head)->next;
		lm_free_node(*head);
		*head = front;
	}
}