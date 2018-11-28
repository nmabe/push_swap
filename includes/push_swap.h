/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:12:20 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/27 11:22:46 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# define GREEN "\033[22;32m"
# define RED "\033[22;31m"
# define BLUE "\033[22;34m"
# define RESET "\033[22;0m"
# define MAX_INT 217473647
# define MIN_INT -217473648

typedef struct		s_lists
{
	int				data;
	struct s_lists	*next;
}					t_lists;

typedef struct		s_flags
{
	int				color;
	int				display;
	int				args;
	char			*action;
}					t_flags;

t_lists				*ps_last_node(t_lists **stack);
int					ps_lstlen(t_lists **head);
void				ps_push_args(t_list **adjures, char *str);
void				ps_push(t_lists **head, int n);
void				ps_free_stack(t_lists **stack_a, t_lists **stack_b);
void				chk_free_stack(t_lists **stack_a, t_lists **stack_b,
		t_list **actions);
void				ps_free_args(char **args, int argc);
int					ps_check_sorted(t_lists **stack_a);
int					ps_rev_sorted(t_lists **stack_a);
void				ps_error(t_lists **stack_a, t_lists **stack_b);
void				ps_get_args(char **av, int ac, t_lists **stk, t_flags *flg);
char				**ps_get_argv(char **argv, int *argc);
void				ps_print_stacks(t_lists **stack_a, t_lists **stack_b,
		int c);
void				ps_print_list(t_lists *head);
void				ps_swap_a(t_lists *stack_a);
void				ps_push_a(t_lists **stack_a, t_lists **stack_b);
void				ps_rot_ra(t_lists **stack_a);
void				ps_rot_a(t_lists **stack_a);
int					chk_push_swap(t_lists **head_a, t_list **args,
		t_flags *flag);
void				push_swap(t_lists **stack_a, t_lists **stack_b);
char				*handler(t_lists **stack_a, t_lists **stack_b, int lstlen);
int					ps_get_max_pos(t_lists **stack_a, t_lists **stack_b);
int					ps_get_rev_pos(int num, int len, t_lists **stack);
int					ps_get_max(t_lists **stack);
int					ps_get_pos(int num, t_lists **stack);
int					ps_get_min(t_lists **stack);
int					ps_det_moves(t_lists **stack_a, t_lists **stack_b, int num);
int					ps_det_steps(t_lists **stack_a, t_lists **stack_b, int num);
char				*ps_sort_one(t_lists **stack_a);
char				*ps_sort_ten(t_lists **stack_a, t_lists **stack_b);

#endif
