/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:04:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:38:19 by unite            ###   ########.fr       */
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

void			simple_sort(t_stack *sa, t_stack *sb);
void			advanced_sort(t_stack *sa, t_stack *sb);
void			advanced_merge_stacks(t_stack *st_a, t_stack *st_b);

void			advanced_push_ra_rb(t_stack *st_a, t_stack *st_b,
									int ra, int rb);
void			advanced_push_rra_rb(t_stack *st_a, t_stack *st_b,
									int rra, int rb);
void			advanced_push_ra_rrb(t_stack *st_a, t_stack *st_b,
									int ra, int rrb);
void			advanced_push_rra_rrb(t_stack *st_a, t_stack *st_b,
									int rra, int rrb);

int				ps_atoi(const char *str, int *resp);
void			ps_exit(int code);
int				ps_index_stack(t_stack *stack);
int				ps_isnumeric_str(const char *str);
int				ps_tab2stack(char **tab, t_stack *stack);

void			set_verbose(int code);
void			perform_operation(t_stack *st_a, t_stack *st_b, char *oper);
void			perform_pa(t_stack *st_a, t_stack *st_b);
void			perform_pb(t_stack *st_a, t_stack *st_b);
void			perform_ra(t_stack *st_a, t_stack *st_b);
void			perform_rb(t_stack *st_a, t_stack *st_b);
void			perform_rr(t_stack *st_a, t_stack *st_b);
void			perform_rra(t_stack *st_a, t_stack *st_b);
void			perform_rrb(t_stack *st_a, t_stack *st_b);
void			perform_rrr(t_stack *st_a, t_stack *st_b);
void			perform_sa(t_stack *st_a, t_stack *st_b);
void			perform_sb(t_stack *st_a, t_stack *st_b);
void			perform_ss(t_stack *st_a, t_stack *st_b);

#endif
