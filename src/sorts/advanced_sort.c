/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 22:24:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	push_once(t_stack *stackA, t_stack *stackB, int ceil)
{
	int		iA;
	int		jA;
	int		value;
	int		iB;
	int		jB;

	iA = search_stack(stackA, ceil, -1);
	jA = reverse_search_stack(stackA, ceil, -1) + 1;
	value = iA < jA ? get_stack(stackA, iA) : reverse_get_stack(stackA, jA);
	iB = search_stack(stackB, value, 1);
	jB = reverse_search_stack(stackB, value, 1) + 1;
	if (iA < jA && iB < jB)
		prepare_stacks_fwd_fwd(stackA, stackB, iA, iB);
	if (iA < jA && iB > jB)
		prepare_stacks_fwd_rev(stackA, stackB, iA, jB);
	if (iA > jA && iB < jB)
		prepare_stacks_rev_fwd(stackA, stackB, jA, iB);
	if (iA > jA && iB > jB)
		prepare_stacks_rev_rev(stackA, stackB, jA, jB);
	perform_operation(stackA, stackB, 'pb');
}

void		advanced_sort(t_stack *stackA, t_stack *stackB)
{
	size_t		batchsize;
	int 		i;
	int			j;

	batchsize = stackA->size / NBATCHES;
	i = 0;
	while (i++ < NBATCHES - 1)
	{
		j = 0;
		while (j++ < batchsize)
			push_once(stackA, stackB, batchsize * i);
	}
	while (stackA->size > 0)
		push_once(stackA, stackB, INT_MAX);
	while (stackB->start->value != stackB->size)
		perform_operation(stackA, stackB, 'rrb');
	while (stackB->start)
		perform_operation(stackA, stackB, 'pa');
}
