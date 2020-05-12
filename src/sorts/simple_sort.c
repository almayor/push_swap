/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:07:16 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 00:32:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     sort_stackA(t_stack *stackA, t_stack *stackB)
{
	int max;

	max = max_stack(stackA);
	if (stackA->start->value == max)
		perform_operation(stackA, stackB, "ra");
	if (stackA->size > 2 && stackA->start->next->value == max)
		perform_operation(stackA, stackB, "rra");
	if (stackA->start->value > stackA->start->next->value)
		perform_operation(stackA, stackB, "sa");
}

static void     sort_stackB(t_stack *stackA, t_stack *stackB)
{
	int min;

	min = min_stack(stackB);
	if (stackB->start->value == min)
		perform_operation(stackA, stackB, "rb");
	if (stackB->size > 2 && stackB->start->next->value == min)
		perform_operation(stackA, stackB, "rrb");
	if (stackB->start->value < stackB->start->next->value)
		perform_operation(stackA, stackB, "sb");
}

static void      split_stackA(t_stack *stackA, t_stack *stackB, int minbound)
{
	int  i;
	int 	n;

	i = 0;
	n = stackA->size;
	while (i < n)
	{
		if (stackA->start->value <= minbound)
			perform_operation(stackA, stackB, "pb");
		else
			perform_operation(stackA, stackB, "ra");
		i++;
	}
}

static void      merge_stacks(t_stack *stackA, t_stack *stackB)
{
	while (stackB->start)
		perform_operation(stackA, stackB, "pa");
}

void         	simple_sort(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size < 2)
		return ;
	if (stackA->size <= 3)
		sort_stackA(stackA, stackB);
	else
	{
		split_stackA(stackA, stackB, avg_stack(stackA));
		sort_stackA(stackA, stackB);
		sort_stackB(stackA, stackB);
		merge_stacks(stackA, stackB);
	}
}

