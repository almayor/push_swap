/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:37:19 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 15:54:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_search.h"

static int	expand_fringe(t_heap *fringe, t_state *parent)
{
	static char	*opers[] = {
		"ra", "rb", "rr", "rra", "rrb", "rrr", "sa", "sb", "ss", "pa", "pb"
	};
	int			i;
	int			rc;
	t_state 	*child;

	i = 0;
	while (i < 11)
	{
		rc = succeed_state(parent, &child, opers[i++]);
		if (rc < 0)
			continue ;
		if (rc == 1)
			return (1);
		if (push_heap(fringe, child->h + child->g, (void *)child))
			return (1);
	}
	return (0);
}

static int	cleanup_fringe(t_heap *fringe)
{
	t_state	*state;

	if (!fringe)
		return (0);
	while (pop_heap(fringe, (void **)&state) == 0)
		free_state(state);
	free_heap(fringe);
	return (0);
}

static int	make_fringe(t_heap **fringe, t_stack *stackA)
{
	t_state	*state;

	state = 0;
	*fringe = 0;
	if (new_heap(fringe) ||
		new_state(&state, stackA) ||
		push_heap(*fringe, state->h, (void *)state))
	{
		if (state)
			free_state(state);
		if (*fringe)
			cleanup_fringe(*fringe);
		return (1);
	}
	return (0);
}

int			A_search(t_stack *stackA, t_queue **trace)
{
	t_heap	*fringe;
	t_state	*state;

	if (make_fringe(&fringe, stackA))
		return (1);
	while (pop_heap(fringe, (void **)&state) == 0)
	{
		if (is_goal_state(state))
		{
			copy_queue(state->trace, trace);
			free_state(state);
			cleanup_fringe(fringe);
			return (0);
		}
		if (expand_fringe(fringe, state))
		{
			free_state(state);
			cleanup_fringe(fringe);
			return (1);
		}
		free_state(state);
	}
	cleanup_fringe(fringe);
	return (-1);
}
