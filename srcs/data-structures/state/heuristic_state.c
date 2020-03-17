/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:30:05 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 06:32:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

// static int	min_abs(int a, int b)
// {
// 	if (a < 0)
// 		a = -a;
// 	if (b < 0)
// 		b = -b;
// 	return (a < b ? a : b);
// }

// static int	unsorted_pairs(const t_stack *stack)
// {
// 	int		len;
// 	int		i;
// 	int 	nunsorted;
// 	t_ilink	*node;

// 	len = len_stack(stack);
// 	i = 0;
// 	nunsorted = 0;
// 	node = stack->start;
// 	while (node && node->next)
// 	{
// 		if (node->value > node->next->value)
// 			nunsorted += 1 + min_abs(len - i, i - len);
// 		node = node->next;
// 	}
// 	return (nunsorted);
// }

// static int	sorted_pairs(const t_stack *stack)
// {
// 	int		len;
// 	int		i;
// 	int 	nsorted;
// 	t_ilink	*node;

// 	len = len_stack(stack);
// 	i = 0;
// 	nsorted = 0;
// 	node = stack->start;
// 	while (node && node->next)
// 	{
// 		if (node->value < node->next->value)
// 			nsorted += 1 + min_abs(len - i, i - len);
// 		node = node->next;
// 	}
// 	return (nsorted);
// }

int			heuristic_state(const t_state *state)
{
	return (unsorted_pairs(state->stackA) +
			sorted_pairs(state->stackB) +
			len_stack(state->stackB));
}
