/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:45:23 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 16:33:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_PRIVATE_H
# define OPERATIONS_PRIVATE_H

# include "stack.h"

typedef struct	s_operation
{
	char	*name;
	int		(*fun)(t_stack *, t_stack *);
}				t_operation;

int				perform_pa(t_stack *sa, t_stack *sb);
int				perform_pb(t_stack *sa, t_stack *sb);
int				perform_ra(t_stack *sa, t_stack *sb);
int				perform_rb(t_stack *sa, t_stack *sb);
int				perform_rr(t_stack *sa, t_stack *sb);
int				perform_rra(t_stack *sa, t_stack *sb);
int				perform_rrb(t_stack *sa, t_stack *sb);
int				perform_rrr(t_stack *sa, t_stack *sb);
int				perform_sa(t_stack *sa, t_stack *sb);
int				perform_sb(t_stack *sa, t_stack *sb);
int				perform_ss(t_stack *sa, t_stack *sb);

#endif
