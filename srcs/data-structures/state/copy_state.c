/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:42:55 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 09:08:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int copy_state(const t_state *state1, t_state **state2)
{
	if (!(*state2 = malloc(sizeof(t_state))))
		return (1);
	(*state2)->stackA = 0;
	(*state2)->stackB = 0;
	(*state2)->trace = 0;
	(*state2)->g = state1->g;
	(*state2)->h = state1->h;
	if (copy_stack(state1->stackA, &(*state2)->stackA) ||
		copy_stack(state1->stackB, &(*state2)->stackB) ||
		copy_queue(state1->trace, &(*state2)->trace))
	{
		free_state(*state2);
		return (1);
	}
	return (0);
}
