/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_prepare_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:10:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/17 02:18:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stacks_ra_rb(t_stack *stack_a, t_stack *stack_b,
							int n_ra, int n_rb)
{
	while (n_ra > 0 && n_rb > 0)
	{
		perform_operation(stack_a, stack_b, "rr");
		--n_ra;
		--n_rb;
	}
	while (n_ra-- > 0)
		perform_operation(stack_a, stack_b, "ra");
	while (n_rb-- > 0)
		perform_operation(stack_a, stack_b, "rb");
}

void	prepare_stacks_rra_rrb(t_stack *stack_a, t_stack *stack_b,
							int n_rra, int n_rrb)
{
	while (n_rra > 0 && n_rrb > 0)
	{
		perform_operation(stack_a, stack_b, "rrr");
		--n_rra;
		--n_rrb;
	}
	while (n_rra-- > 0)
		perform_operation(stack_a, stack_b, "rra");
	while (n_rrb-- > 0)
		perform_operation(stack_a, stack_b, "rrb");
}

void	prepare_stacks_ra_rrb(t_stack *stack_a, t_stack *stack_b,
							int n_ra, int n_rrb)
{
	while (n_ra-- > 0)
		perform_operation(stack_a, stack_b, "ra");
	while (n_rrb-- > 0)
		perform_operation(stack_a, stack_b, "rrb");
}

void	prepare_stacks_rra_rb(t_stack *stack_a, t_stack *stack_b,
							int n_rra, int n_rb)
{
	while (n_rra-- > 0)
		perform_operation(stack_a, stack_b, "rra");
	while (n_rb-- > 0)
		perform_operation(stack_a, stack_b, "rb");
}
