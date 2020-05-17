/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:04:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 00:41:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintfgnl.h"
# include "stack.h"
# include <errno.h>
# include <limits.h>

typedef struct	s_operation
{
	char	*name;
	void	(*fun)(t_stack *, t_stack *);
}				t_operation;

void			advanced_sort(t_stack *sa, t_stack *sb);
void			simple_sort(t_stack *sa, t_stack *sb);
void			set_verbose(int code);
void			perform_operation(t_stack *sa, t_stack *sb, char *oper);

int				ps_atoi(const char *str, int *resp);
void			ps_exit(int code);
int				ps_index_stack(t_stack *stack);
int				ps_isnumeric_str(const char *str);
int				ps_tab2stack(char **tab, t_stack *stack);

void			perform_pa(t_stack *stack_a, t_stack *stack_b);
void			perform_pb(t_stack *stack_a, t_stack *stack_b);
void			perform_ra(t_stack *stack_a, t_stack *stack_b);
void			perform_rb(t_stack *stack_a, t_stack *stack_b);
void			perform_rr(t_stack *stack_a, t_stack *stack_b);
void			perform_rra(t_stack *stack_a, t_stack *stack_b);
void			perform_rrb(t_stack *stack_a, t_stack *stack_b);
void			perform_rrr(t_stack *stack_a, t_stack *stack_b);
void			perform_sa(t_stack *stack_a, t_stack *stack_b);
void			perform_sb(t_stack *stack_a, t_stack *stack_b);
void			perform_ss(t_stack *stack_a, t_stack *stack_b);

void			prepare_stacks_ra_rb(t_stack *stack_a, t_stack *stack_b,
							int n_ra, int n_rb);
void			prepare_stacks_rra_rrb(t_stack *stack_a, t_stack *stack_b,
							int n_rra, int n_rrb);
void			prepare_stacks_ra_rrb(t_stack *stack_a, t_stack *stack_b,
							int n_ra, int n_rrb);
void			prepare_stacks_rra_rb(t_stack *stack_a, t_stack *stack_b,
							int n_rra, int n_rb);

#endif
