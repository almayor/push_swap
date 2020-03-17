/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:45:23 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:39:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"
# include "stack.h"

typedef struct		s_operation
{
	char			*name;
	int				(*function)(t_stack *, t_stack *);
}					t_operation;

int	perform_operation(t_stack *stackA, t_stack *stackB, char *oper);

int	perform_pa(t_stack *stackA, t_stack *stackB);
int	perform_pb(t_stack *stackA, t_stack *stackB);
int	perform_ra(t_stack *stackA, t_stack *stackB);
int	perform_rb(t_stack *stackA, t_stack *stackB);
int	perform_rr(t_stack *stackA, t_stack *stackB);
int	perform_rra(t_stack *stackA, t_stack *stackB);
int	perform_rrb(t_stack *stackA, t_stack *stackB);
int	perform_rrr(t_stack *stackA, t_stack *stackB);
int	perform_sa(t_stack *stackA, t_stack *stackB);
int	perform_sb(t_stack *stackA, t_stack *stackB);
int	perform_ss(t_stack *stackA, t_stack *stackB);

#endif
