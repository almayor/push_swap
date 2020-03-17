/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succeed_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:43:29 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:18:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int succeed_state(const t_state *parent, t_state **child, char *oper)
{
	int	rc;

	if (copy_state(parent, child))
		return (1);
	if ((rc = enqueue_queue((*child)->trace, oper)) ||
		(rc = perform_operation((*child)->stackA, (*child)->stackB, oper)))
	{
		free_state(*child);
		return (rc);
	}
	(*child)->g = parent->g + 1;
	(*child)->h = heuristic_state(*child);
	return (0);
}
