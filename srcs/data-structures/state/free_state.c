/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:42:00 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 08:28:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int free_state(t_state *state)
{
	if (!state)
		return (0);
	if (state->stackA)
		free_stack(state->stackA);
	if (state->stackB)
		free_stack(state->stackB);
	if (state->trace)
		free_queue(state->trace);
	free(state);
	return (0);
}
