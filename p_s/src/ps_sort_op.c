/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:30:47 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:40:11 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		ps_push_swap(t_lists **stack_a, t_lists **stack_b, char *handle)
{
	if (ft_strcmp(handle, "rr") == 0)
	{
		ps_rot_a(stack_a);
		ps_rot_a(stack_b);
	}
	else if (ft_strcmp(handle, "rra") == 0)
		ps_rot_ra(stack_a);
	else if (ft_strcmp(handle, "rrb") == 0)
		ps_rot_ra(stack_b);
	else if (ft_strcmp(handle, "rrr") == 0)
	{
		ps_rot_ra(stack_a);
		ps_rot_ra(stack_b);
	}
}

char			*ps_sort_one(t_lists **stack_a)
{
	t_lists		*temp;

	temp = *stack_a;
	if (ps_check_sorted(&temp) == 1)
		return ("OK");
	else if (temp->data == ps_get_max(&temp) && ps_rev_sorted(&temp) == 1)
		return ("ra");
	else if (temp->next->data == ps_get_min(&temp))
		return ("sa");
	return ("rra");
}

char			*ps_sort_ten(t_lists **stk_a, t_lists **stk_b)
{
	int			len;

	len = ps_lstlen(stk_a);
	if (ps_check_sorted(stk_a) == 1 && *stk_b == NULL)
		return ("OK");
	else if (ps_check_sorted(stk_a) == 1 && ps_rev_sorted(stk_b) && *stk_b)
		return ("pa");
	if (len == 3)
	{
		if (ft_strcmp("OK", ps_sort_one(stk_a)) == 0)
			return ("pa");
		else
			return (ps_sort_one(stk_a));
	}
	if ((*stk_a)->data == ps_get_min(stk_a))
		return ("pb");
	else
		return ((ps_get_pos(ps_get_min(stk_a), stk_a) <=
		len / 2) ? "ra" : "rra");
}

void			push_swap(t_lists **stack_a, t_lists **stack_b)
{
	char		*handle;

	handle = "ret";
	handle = handler(stack_a, stack_b, ps_lstlen(stack_a));
	while (ft_strcmp("OK", handle) != 0)
	{
		ft_putendl(handle);
		if (ft_strcmp(handle, "sa") == 0)
			ps_swap_a(*stack_a);
		else if (ft_strcmp(handle, "sb") == 0)
			ps_swap_a(*stack_b);
		else if (ft_strcmp(handle, "pa") == 0)
			ps_push_a(stack_b, stack_a);
		else if (ft_strcmp(handle, "pb") == 0)
			ps_push_a(stack_a, stack_b);
		else if (ft_strcmp(handle, "ra") == 0)
			ps_rot_a(stack_a);
		else if (ft_strcmp(handle, "rb") == 0)
			ps_rot_a(stack_b);
		else
			ps_push_swap(stack_a, stack_b, handle);
		handle = handler(stack_a, stack_b, ps_lstlen(stack_a));
	}
}
