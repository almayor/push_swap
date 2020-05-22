/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:07:16 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 03:17:32 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_st_a(t_stack *st_a, t_stack *st_b)
{
	int max;

	max = max_stack(st_a);
	if (st_a->start->value == max)
		perform_operation(st_a, st_b, "ra");
	if (st_a->size > 2 && st_a->start->next->value == max)
		perform_operation(st_a, st_b, "rra");
	if (st_a->start->value > st_a->start->next->value)
		perform_operation(st_a, st_b, "sa");
}

static void		sort_st_b(t_stack *st_a, t_stack *st_b)
{
	int min;

	min = min_stack(st_b);
	if (st_b->start->value == min)
		perform_operation(st_a, st_b, "rb");
	if (st_b->size > 2 && st_b->start->next->value == min)
		perform_operation(st_a, st_b, "rrb");
	if (st_b->start->value < st_b->start->next->value)
		perform_operation(st_a, st_b, "sb");
}

static void		split_st_a(t_stack *st_a, t_stack *st_b, int minbound)
{
	int	i;
	int	n;

	i = 0;
	n = st_a->size;
	while (errno == 0 && i < n)
	{
		if (st_a->start->value <= minbound)
			perform_operation(st_a, st_b, "pb");
		else
			perform_operation(st_a, st_b, "ra");
		i++;
	}
}

static void		merge_stacks(t_stack *st_a, t_stack *st_b)
{
	while (errno == 0 && st_b->start)
		perform_operation(st_a, st_b, "pa");
}

void			simple_sort(t_stack *st_a, t_stack *st_b)
{
	if (st_a->size < 2)
		return ;
	if (st_a->size <= 3)
		sort_st_a(st_a, st_b);
	else if (!isordered_stack(st_a))
	{
		split_st_a(st_a, st_b, avg_stack(st_a));
		sort_st_a(st_a, st_b);
		sort_st_b(st_a, st_b);
		merge_stacks(st_a, st_b);
	}
}
