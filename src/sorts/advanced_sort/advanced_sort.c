/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 04:31:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/24 05:07:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	blind_split_stacks(t_stack *st_a, t_stack *st_b)
{
	while (st_a->size > 2)
	{
		if (st_a->start->value == 1)
			perform_operation(st_a, st_b, "ra");
		else
			perform_operation(st_a, st_b, "pb");
	}
}

void		advanced_sort(t_stack *st_a, t_stack *st_b)
{
	if (!issorted_stack(st_a))
	{
		blind_split_stacks(st_a, st_b);
		advanced_merge_stacks(st_a, st_b);
	}
}
