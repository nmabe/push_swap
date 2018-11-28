/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:10:25 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:43:14 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ps_swap_a(t_lists *stack_a)
{
	if (stack_a != NULL && stack_a->next != NULL)
	{
		ft_swap(&stack_a->data, &stack_a->next->data);
	}
}

void			ps_push_a(t_lists **stack_a, t_lists **stack_b)
{
	t_lists		*curr;
	t_lists		*ptr;

	ptr = *stack_a;
	curr = NULL;
	if (ptr != NULL)
	{
		curr = ptr->next;
		ptr->next = *stack_b;
		*stack_b = ptr;
		ptr = curr;
		*stack_a = ptr;
	}
}

void			ps_rot_ra(t_lists **stack_a)
{
	t_lists		*s_last;
	t_lists		*last;

	last = *stack_a;
	if (last == NULL || last->next == NULL)
		return ;
	while (last->next != NULL)
	{
		s_last = last;
		last = last->next;
	}
	s_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void			ps_rot_a(t_lists **stack_a)
{
	t_lists		*first;
	t_lists		*last;

	last = *stack_a;
	if ((*stack_a)->next == NULL || *stack_a == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->next != NULL)
		last = last->next;
	(*stack_a) = first->next;
	first->next = NULL;
	last->next = first;
}
