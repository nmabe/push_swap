/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:05:41 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:46:35 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			ps_check_flag(t_flags *flags, char *str)
{
	t_lists			*stack_a;

	stack_a = NULL;
	if (ft_strcmp("-c", str) == 0)
		flags->color = 1;
	else if (ft_strcmp("-v", str) == 0)
		flags->display = 1;
	else if (ft_strcmp("-cv", str) == 0 || ft_strcmp("-vc", str) == 0)
	{
		flags->color = 1;
		flags->display = 1;
	}
	else
		ps_error(&stack_a, &stack_a);
}

static int			ps_is_dup(t_lists **stack_a, int n)
{
	t_lists			*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->data == n)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static long long	ps_int(const char *str)
{
	long long		digit;
	long long		sign;

	digit = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		digit = digit * 10 + (*str++ - '0');
	return (digit * sign);
}

static int			ps_isvalid(char *str, t_lists **stack_a)
{
	long long		n;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			return (0);
		i++;
	}
	n = ps_int(str);
	if ((n > MAX_INT) || (n < MIN_INT))
		return (0);
	else if (ps_is_dup(stack_a, n) == 0)
		return (0);
	else
		return (1);
}

void				ps_get_args(char **av, int ac, t_lists **stk, t_flags *flg)
{
	int				i;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			if (ft_isalpha(av[i][0]) == 1)
				ps_error(stk, stk);
			if (av[i][0] == '-' && ft_isalpha(av[i][1]))
				ps_check_flag(flg, av[i]);
			else if (ps_isvalid(av[i], stk))
				ps_push(stk, ft_atoi(av[i]));
			else
			{
				(ac <= 3) ? ps_free_args(av, ac) : 0;
				ps_error(stk, stk);
			}
		}
		(ac <= 3) ? ps_free_args(av, ac) : 0;
	}
}
