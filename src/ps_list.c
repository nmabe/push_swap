/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:10:08 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:46:58 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ps_lstlen(t_lists **head)
{
	int			i;
	t_lists		*lst;

	lst = *head;
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lists			*ps_last_node(t_lists **stack)
{
	t_lists		*last;

	last = *stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void			ps_push_args(t_list **adjures, char *str)
{
	t_list		*new;
	t_list		*last;

	last = *adjures;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return ;
	new->content = (void *)str;
	new->content_size = ft_strlen(str);
	new->next = NULL;
	if (*adjures == NULL)
	{
		*adjures = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void			ps_push(t_lists **head, int n)
{
	t_lists		*last;
	t_lists		*new;

	if (!(new = (t_lists *)malloc(sizeof(t_lists))))
		return ;
	if (new == NULL)
		return ;
	last = *head;
	new->data = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
