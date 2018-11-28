/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:55:37 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:14:24 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		ps_check_action(char *str)
{
	if (ft_strcmp("sa", str) == 0)
		return (1);
	else if (ft_strcmp("sb", str) == 0)
		return (1);
	else if (ft_strcmp("ss", str) == 0)
		return (1);
	else if (ft_strcmp("pa", str) == 0)
		return (1);
	else if (ft_strcmp("pb", str) == 0)
		return (1);
	else if (ft_strcmp("ra", str) == 0)
		return (1);
	else if (ft_strcmp("rb", str) == 0)
		return (1);
	else if (ft_strcmp("rr", str) == 0)
		return (1);
	else if (ft_strcmp("rra", str) == 0)
		return (1);
	else if (ft_strcmp("rrb", str) == 0)
		return (1);
	else if (ft_strcmp("rrr", str) == 0)
		return (1);
	return (0);
}

void			chk_error(t_lists **stk_a, t_lists **stk_b, t_list **args)
{
	chk_free_stack(stk_a, stk_b, args);
	ft_putendl("Error");
	exit(1);
}

void			ps_result(t_flags *f, int i)
{
	if (i == 1)
	{
		if (f->color == 1)
			ft_putstr(GREEN);
		ft_putendl("OK");
	}
	else if (i == 0)
	{
		if (f->color == 1)
			ft_putstr(RED);
		ft_putendl("KO");
	}
	(f->color) ? ft_putstr(RESET) : 0;
}

static void		ps_init(t_flags *f, t_list **a, t_lists **s)
{
	*s = NULL;
	*a = NULL;
	f->action = NULL;
	f->args = 0;
	f->color = 0;
	f->display = 0;
}

int				main(int argc, char **argv)
{
	t_lists		*stack_a;
	t_list		*args;
	t_flags		flags;
	char		*line;
	char		**arg;

	ps_init(&flags, &args, &stack_a);
	if (argc >= 2)
	{
		flags.args = argc;
		arg = ps_get_argv(argv,&argc);
		ps_get_args(arg, argc, &stack_a, &flags);
		while (get_next_line(0, &line) > 0)
		{
			if (ps_check_action(line) == 0)
			{
				ft_strdel(&line);
				chk_error(&stack_a, &stack_a, &args);
			}
			ps_push_args(&args, line);
		}
		ps_result(&flags, chk_push_swap(&stack_a, &args, &flags));
	}
	return (1);
}
