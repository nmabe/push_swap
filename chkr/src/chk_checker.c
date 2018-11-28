/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:10:25 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:20:56 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		chk_rotate_stacks(t_flags *s, t_lists **stk_a, t_lists **stk_b)
{
	if (s->display)
	{
		if (s->color)
			ft_putstr(GREEN);
		ft_putendl(s->action);
	}
	if (ft_strcmp("ra", s->action) == 0)
		ps_rot_a(stk_a);
	else if (ft_strcmp("rb", s->action) == 0)
		ps_rot_a(stk_b);
	else if (ft_strcmp("rra", s->action) == 0)
		ps_rot_ra(stk_a);
	else if (ft_strcmp("rrb", s->action) == 0)
		ps_rot_ra(stk_b);
	if (ft_strcmp("rr", s->action) == 0)
	{
		ps_rot_a(stk_a);
		ps_rot_a(stk_b);
	}
	else if (ft_strcmp("rrr", s->action) == 0)
	{
		ps_rot_ra(stk_a);
		ps_rot_ra(stk_b);
	}
	(s->color) ? ft_putstr(RESET) : 0;
}

static void		chk_swap_stacks(t_flags *s, t_lists **stk_a, t_lists **stk_b)
{
	if (s->display)
	{
		if (s->color)
			ft_putstr(GREEN);
		ft_putendl(s->action);
	}
	if (ft_strcmp("sa", s->action) == 0)
	{
		ps_swap_a(*stk_a);
	}
	else if (ft_strcmp("sb", s->action) == 0)
	{
		ps_swap_a(*stk_b);
	}
	else if (ft_strcmp("ss", s->action) == 0)
	{
		ps_swap_a(*stk_a);
		ps_swap_a(*stk_b);
	}
	(s->color) ? ft_putstr(RESET) : 0;
}

static void		chk_push_stacks(t_flags *s, t_lists **stk_a, t_lists **stk_b)
{
	if (s->display)
	{
		if (s->color)
			ft_putstr(GREEN);
		ft_putendl(s->action);
	}
	if (ft_strcmp("pa", s->action) == 0)
	{
		ps_push_a(stk_b, stk_a);
	}
	else if (ft_strcmp("pb", s->action) == 0)
	{
		ps_push_a(stk_a, stk_b);
	}
	(s->color) ? ft_putstr(RESET) : 0;
}

int				chk_push_swap(t_lists **head_a, t_list **args, t_flags *flag)
{
	t_lists		*stk_a;
	t_lists		*stk_b;
	t_list		*tmp;
	int			r;

	stk_a = *head_a;
	stk_b = NULL;
	(flag->display) ? ps_print_stacks(&stk_a, &stk_b, 0) : 0;
	tmp = *args;
	while (tmp != NULL)
	{
		flag->action = ft_strdup((const char *)tmp->content);
		if (flag->action[0] == 's')
			chk_swap_stacks(flag, &stk_a, &stk_b);
		else if (flag->action[0] == 'p')
			chk_push_stacks(flag, &stk_a, &stk_b);
		else if (flag->action[0] == 'r')
			chk_rotate_stacks(flag, &stk_a, &stk_b);
		tmp = tmp->next;
		(flag->display) ? ps_print_stacks(&stk_a, &stk_b, flag->color) : 0;
		free(flag->action);
	}
	r = ps_check_sorted(&stk_a);
	chk_free_stack(&stk_a, &stk_b, args);
	return (r);
}
