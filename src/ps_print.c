/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:42:40 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:49:41 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_count(const char *s, char c)
{
	int			counter1;
	int			substr1;

	substr1 = 0;
	counter1 = 0;
	while (*s != '\0')
	{
		if (substr1 == 1 && *s == c)
			substr1 = 0;
		if (substr1 == 0 && *s != c)
		{
			substr1 = 1;
			counter1++;
		}
		s++;
	}
	return (counter1);
}

char			**ps_get_argv(char **argv, int *argc)
{
	char		*str;
	char		*tmp;
	char		**ret;

	if (*argc > 3)
		return (argv);
	str = ft_strjoin(argv[0], " ");
	tmp = str;
	tmp = ft_strjoin(str, argv[1]);
	free(str);
	if (*argc == 3)
	{
		str = tmp;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		tmp = ft_strjoin(str, argv[2]);
		free(str);
	}
	ret = ft_strsplit(tmp, ' ');
	*argc = ft_count(tmp, ' ');
	free(tmp);
	return (ret);
}

void			ps_print_stacks(t_lists **stack_a, t_lists **stack_b, int c)
{
	t_lists		*tmp_a;
	t_lists		*tmp_b;
	int			a;
	int			b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	a = ps_lstlen(&tmp_a);
	b = ps_lstlen(&tmp_b);
	(c == 1) ? ft_putstr(BLUE) : 0;
	ft_putendl("\n********************");
	ft_putendl("stack A	|  stack B\n");
	ft_putendl("--------|------------\n");
	while ((a || b) && (tmp_a != NULL || tmp_b != NULL))
	{
		(a-- > 0) ? ft_putnbr(tmp_a->data) : ft_putchar(45);
		ft_putstr("\t|\t");
		(b-- > 0) ? ft_putnbr(tmp_b->data) : ft_putchar(45);
		(tmp_a != NULL) ? tmp_a = tmp_a->next : 0;
		(tmp_b != NULL) ? tmp_b = tmp_b->next : 0;
		ft_putstr("\n");
	}
	ft_putendl("\n********************\n");
	if (c == 1)
		ft_putstr(RESET);
}

void			ps_free_args(char **av, int ac)
{
	int			i;

	i = 0;
	while (i < ac && av[i])
	{
		ft_strdel(&av[i]);
		i++;
	}
	free(av);
}

void			ps_print_list(t_lists *head)
{
	while (head != NULL)
	{
		ft_putnbr(head->data);
		ft_putendl("");
		head = head->next;
	}
}
