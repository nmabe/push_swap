/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:12:07 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:41:19 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				main(int argc, char **argv)
{
	t_lists		*stack_a;
	t_flags		flags;
	t_lists		*stack_b;
	char		**arg;

	flags.display = 0;
	flags.color = 0;
	flags.args = argc;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		arg = ps_get_argv(argv,&argc);
		ps_get_args(arg, argc, &stack_a, &flags);
		push_swap(&stack_a, &stack_b);
		ps_free_stack(&stack_a, &stack_b);
	}
	return (0);
}
