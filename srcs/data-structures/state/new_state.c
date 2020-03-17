/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:44:05 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 17:10:24 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int	new_state(t_state **state, t_stack *stack)
{
	if (!(*state = malloc(sizeof(t_state))) ||
		copy_stack(stack, &(*state)->stackA) ||
		new_stack(&(*state)->stackB) ||
		new_queue(&(*state)->trace))
		return (1);
	(*state)->g = 0;
	(*state)->h = heuristic_state(*state);
	return (0);
}
