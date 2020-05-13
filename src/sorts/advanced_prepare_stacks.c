/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_prepare_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:10:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:12:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.h"

void	prepare_stacks_fwd_fwd(t_stack *stackA, t_stack *stackB, int iA, int iB)
{
	while (iA > 0 && iB > 0)
	{
		perform_operation(stackA, stackB, 'rrr');
		--iA;
		--iB;
	}
	while (iA-- > 0)
		perform_operation(stackA, stackB, 'rra');
	while (iB-- > 0)
		perform_operation(stackA, stackB, 'rrb');
}

void	prepare_stacks_fwd_rev(t_stack *stackA, t_stack *stackB, int iA, int jB)
{
	while (iA-- > 0)
		perform_operation(stackA, stackB, 'rra');
	while (jB-- > 0)
		perform_operation(stackA, stackB, 'rb');
}

void	prepare_stacks_rev_fwd(t_stack *stackA, t_stack *stackB, int jA, int iB)
{
	while (jA-- > 0)
		perform_operation(stackA, stackB, 'ra');
	while (iB-- > 0)
		perform_operation(stackA, stackB, 'rrb');
}

void	prepare_stacks_rev_rev(t_stack *stackA, t_stack *stackB, int jA, int jB)
{
	while (jA > 0 && jB > 0)
	{
		perform_operation(stackA, stackB, 'rr');
		--jA;
		--jB;
	}
	while (jA-- > 0)
		perform_operation(stackA, stackB, 'ra');
	while (jB-- > 0)
		perform_operation(stackA, stackB, 'rb');
}
