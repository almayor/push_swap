/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 11:18:52 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 16:12:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

static int	unsorted_pairs(const t_stack *stack, int descending)
{
	int 	nunsorted;
	t_ilink	*node;

	nunsorted = 0;
	node = stack->start;
	while (node && node->next)
	{
		if (node->value < node->next->value && descending)
			nunsorted += 1;
		if (node->value > node->next->value && !descending)
			nunsorted += 1;
		node = node->next;
	}
	return (nunsorted);
}

int			heuristic_state(const t_state *state)
{
	return (unsorted_pairs(state->stackA, 0) +
			unsorted_pairs(state->stackB, 1) +
			len_stack(state->stackB));
}
