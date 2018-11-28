/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:14:07 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:37:43 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				ps_get_min(t_lists **stack)
{
	int			min;
	t_lists		*temp;

	temp = *stack;
	min = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data < min)
			min = temp->data;
	}
	return (min);
}

int				ps_get_pos(int num, t_lists **stack)
{
	int			i;
	t_lists		*temp;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		if (num == temp->data)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int				ps_get_max(t_lists **stack)
{
	int			max;
	t_lists		*temp;

	temp = *stack;
	max = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data > max)
			max = temp->data;
	}
	return (max);
}

int				ps_get_rev_pos(int num, int len, t_lists **stack)
{
	int			i;
	int			sort_d;

	i = 0;
	sort_d = ps_rev_sorted(stack);
	if (ps_lstlen(stack) == 1 || ps_lstlen(stack) == 0)
		return (len);
	else if ((i = 0) || (sort_d && (num > (*stack)->data ||
					num < ps_last_node(stack)->data)))
	{
		while (i++ < len)
			ps_rot_ra(stack);
		return (len);
	}
	else if (num > (*stack)->data && num < ps_last_node(stack)->data)
	{
		while (i++ < len)
			ps_rot_ra(stack);
		return (len);
	}
	else
	{
		ps_rot_a(stack);
		return (ps_get_rev_pos(num, len + 1, stack));
	}
}

int				ps_get_max_pos(t_lists **stack_a, t_lists **stack_b)
{
	t_lists		*temp;
	int			i;
	int			num;

	num = (*stack_a)->data;
	if (*stack_b != NULL)
	{
		i = ps_det_steps(stack_a, stack_b, num);
		temp = (*stack_a)->next;
		num = (*stack_a)->data;
		if (temp != NULL)
		{
			while (temp != NULL)
			{
				if (i > ps_det_steps(stack_a, stack_b, temp->data))
				{
					i = ps_det_steps(stack_a, stack_b, temp->data);
					num = temp->data;
				}
				temp = temp->next;
			}
		}
	}
	return (num);
}
