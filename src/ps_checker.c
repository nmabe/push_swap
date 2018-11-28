/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:38:15 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:42:40 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ps_free_stack(t_lists **stack_a, t_lists **stack_b)
{
	t_lists		*tmp;

	tmp = NULL;
	while (*stack_a != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
		tmp = NULL;
	}
	while (*stack_b != NULL)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp);
		tmp = NULL;
	}
}

int				ps_check_sorted(t_lists **stack_a)
{
	t_lists		*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return (1);
	else if (!tmp->next->next)
		return ((tmp->data < tmp->next->data) ? 1 : 0);
	else
	{
		while (tmp->next != NULL)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
}

int				ps_rev_sorted(t_lists **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return (1);
	else if (!(*stack_a)->next->next)
		return (((*stack_a)->data > (*stack_a)->next->data) ? 1 : 0);
	else
	{
		while ((*stack_a) && (*stack_a)->next != NULL)
		{
			if ((*stack_a)->data < (*stack_a)->next->data)
				return (0);
			(*stack_a) = (*stack_a)->next;
		}
		return (1);
	}
}

void			ps_error(t_lists **stack_a, t_lists **stack_b)
{
	ft_putendl("Error");
	if (*stack_a != NULL)
		ps_free_stack(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void			chk_free_stack(t_lists **stk_a, t_lists **stk_b, t_list **as)
{
	t_lists		*tmp;
	t_list		*temp;

	while (*stk_a != NULL)
	{
		tmp = *stk_a;
		*stk_a = (*stk_a)->next;
		free(tmp);
		tmp = NULL;
	}
	while (*stk_b != NULL)
	{
		tmp = *stk_b;
		*stk_b = (*stk_b)->next;
		free(tmp);
		tmp = NULL;
	}
	while (*as != NULL)
	{
		temp = (*as);
		free(temp->content);
		(*as) = (*as)->next;
		free(temp);
		temp = NULL;
	}
}
