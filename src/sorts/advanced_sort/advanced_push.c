/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_push_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:10:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:16:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	advanced_push_stacks_ra_rb(t_stack *st_a, t_stack *st_b,
									int n_ra, int n_rb)
{
	while (n_ra > 0 && n_rb > 0)
	{
		perform_operation(st_a, st_b, "rr");
		--n_ra;
		--n_rb;
	}
	while (n_ra-- > 0)
		perform_operation(st_a, st_b, "ra");
	while (n_rb-- > 0)
		perform_operation(st_a, st_b, "rb");
	perform_operation(st_a, st_b, "pa");
}

void	advanced_push_stacks_rra_rrb(t_stack *st_a, t_stack *st_b,
									int n_rra, int n_rrb)
{
	while (n_rra > 0 && n_rrb > 0)
	{
		perform_operation(st_a, st_b, "rrr");
		--n_rra;
		--n_rrb;
	}
	while (n_rra-- > 0)
		perform_operation(st_a, st_b, "rra");
	while (n_rrb-- > 0)
		perform_operation(st_a, st_b, "rrb");
	perform_operation(st_a, st_b, "pa");
}

void	advanced_push_stacks_ra_rrb(t_stack *st_a, t_stack *st_b,
									int n_ra, int n_rrb)
{
	while (n_ra-- > 0)
		perform_operation(st_a, st_b, "ra");
	while (n_rrb-- > 0)
		perform_operation(st_a, st_b, "rrb");
	perform_operation(st_a, st_b, "pa");
}

void	advanced_push_stacks_rra_rb(t_stack *st_a, t_stack *st_b,
									int n_rra, int n_rb)
{
	while (n_rra-- > 0)
		perform_operation(st_a, st_b, "rra");
	while (n_rb-- > 0)
		perform_operation(st_a, st_b, "rb");
	perform_operation(st_a, st_b, "pa");
}
