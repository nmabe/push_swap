/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:48:56 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:34:30 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char		*ps_sort_stack(t_lists **stk_a, t_lists **stk_b, int i)
{
	int			move;
	int			len_a;
	int			len_b;

	len_a = ps_lstlen(stk_a);
	len_b = ps_lstlen(stk_b);
	move = ps_det_moves(stk_a, stk_b, i);
	if (move < 0)
		return ("rrr");
	else if (move > 0)
		return ("rr");
	else
	{
		if (i != (*stk_a)->data)
			return ((ps_get_pos(i, stk_a) <= len_a / 2) ? "ra" : "rra");
		else
		{
			if (ps_get_rev_pos(i, 0, stk_b) == 0)
				return ("pb");
			else
				return ((ps_get_rev_pos(i, 0, stk_b) <= len_b / 2) ? "rb" :
						"rrb");
		}
	}
}

static int		ps_handler(t_lists **stack_a, t_lists **stack_b)
{
	if (ps_check_sorted(stack_a) && !*stack_b)
		return (1);
	else if (ps_check_sorted(stack_a) && ps_rev_sorted(stack_b) && *stack_b
			&& ((*stack_a)->data > (*stack_b)->data))
		return (2);
	else if (ps_check_sorted(stack_a) && !ps_rev_sorted(stack_b) && *stack_b
			&& (!*stack_a || (*stack_a)->data) > ps_get_max(stack_b))
		return (3);
	return (0);
}

int				ps_det_moves(t_lists **stack_a, t_lists **stack_b, int num)
{
	int			h;
	int			m;
	int			mm;
	int			l;

	h = MAX_NUM(ps_get_pos(num, stack_a), ps_get_rev_pos(num, 0, stack_b));
	l = MAX_NUM(ps_lstlen(stack_a) - ps_get_pos(num, stack_a) + 1,
	ps_lstlen(stack_b) - ps_get_rev_pos(num, 0, stack_b) + 1);
	m = ps_get_pos(num, stack_a) + ps_lstlen(stack_b) -
	ps_get_rev_pos(num, 0, stack_b) + 1;
	mm = ps_lstlen(stack_a) - ps_get_pos(num, stack_a) + ps_get_rev_pos(num,
			0, stack_b);
	if (ps_get_pos(num, stack_a) == 0 || ps_get_rev_pos(num, 0, stack_b) == 0)
		return (0);
	else if (h < l && h < MIN_NUM(m, mm))
		return (1);
	else if (l < h && l < MIN_NUM(m, mm))
		return (-1);
	else
		return (0);
}

int				ps_det_steps(t_lists **stack_a, t_lists **stack_b, int num)
{
	int			h;
	int			l;
	int			m;
	int			mm;

	h = MAX_NUM(ps_get_pos(num, stack_a), ps_get_rev_pos(num, 0, stack_b));
	m = ps_get_pos(num, stack_a) + ps_lstlen(stack_b)
		- ps_get_rev_pos(num, 0, stack_b) + 1;
	mm = ps_lstlen(stack_a) - ps_get_pos(num, stack_a)
		+ 1 + ps_get_rev_pos(num, 0, stack_b);
	l = MAX_NUM(ps_lstlen(stack_a) - ps_get_pos(num, stack_a)
		+ 1, ps_lstlen(stack_b) - ps_get_rev_pos(num, 0, stack_b) + 1);
	if (h < l && h < MIN_NUM(m, mm))
		return (h);
	else if (l < h && l < MIN_NUM(m, mm))
		return (l);
	else
		return (MIN_NUM(m, mm));
}

char			*handler(t_lists **stack_a, t_lists **stack_b, int lstlen)
{
	int			i;
	int			ps;

	i = 0;
	ps = 0;
	if (lstlen == 2)
		return ((ps_check_sorted(stack_a) && *stack_b == NULL) ? "OK" : "sa");
	else if (lstlen == 3)
		return (ps_sort_one(stack_a));
	else if (lstlen <= 10)
		return (ps_sort_ten(stack_a, stack_b));
	else
	{
		ps = ps_handler(stack_a, stack_b);
		if (ps == 1 )
			return ("OK");
		else if (ps == 2)
			return ("pa");
		else if (ps == 3)
			return ((ps_get_pos(ps_get_min(stack_b), stack_b)
						< (ps_lstlen(stack_b) / 2)) ? "rb" : "rrb");
		else
		{
			i = ps_get_max_pos(stack_a, stack_b);
			return (ps_sort_stack(stack_a, stack_b, i));
		}
	}
}
