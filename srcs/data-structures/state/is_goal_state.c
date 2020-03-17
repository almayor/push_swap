/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_goal_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:44:22 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 17:17:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int	is_goal_state(const t_state *state)
{
	if (!is_empty_stack(state->stackB))
		return (0);
	if (!is_sorted_stack(state->stackA))
		return (0);
	return (1);
}
