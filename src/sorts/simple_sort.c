/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:07:16 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 00:55:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{

	int max;

	max = max_stack(stack_a);
	if (stack_a->start->value == max)
		perform_operation(stack_a, stack_b, "ra");
	if (stack_a->size > 2 && stack_a->start->next->value == max)
		perform_operation(stack_a, stack_b, "rra");
	if (stack_a->start->value > stack_a->start->next->value)
		perform_operation(stack_a, stack_b, "sa");
}

static void     sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int min;

	min = min_stack(stack_b);
	if (stack_b->start->value == min)
		perform_operation(stack_a, stack_b, "rb");
	if (stack_b->size > 2 && stack_b->start->next->value == min)
		perform_operation(stack_a, stack_b, "rrb");
	if (stack_b->start->value < stack_b->start->next->value)
		perform_operation(stack_a, stack_b, "sb");
}

static void      split_stack_a(t_stack *stack_a, t_stack *stack_b, int minbound)
{
	int	i;
	int	n;

	i = 0;
	n = stack_a->size;
	while (errno == 0 && i < n)
	{
		if (stack_a->start->value <= minbound)
			perform_operation(stack_a, stack_b, "pb");
		else
			perform_operation(stack_a, stack_b, "ra");
		i++;
	}
}

static void      merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (errno == 0 && stack_b->start)
		perform_operation(stack_a, stack_b, "pa");
}

void         	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		return ;
	if (stack_a->size <= 3)
		sort_stack_a(stack_a, stack_b);
	else if (!issorted_stack(stack_a))
	{
		split_stack_a(stack_a, stack_b, avg_stack(stack_a));
		sort_stack_a(stack_a, stack_b);
		sort_stack_b(stack_a, stack_b);
		merge_stacks(stack_a, stack_b);
	}
}
