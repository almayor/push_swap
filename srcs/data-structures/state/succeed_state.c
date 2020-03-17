/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succeed_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:43:29 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 12:34:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

static int	is_backtracking(char *oper, char *last_oper)
{
	if (ft_strequ(oper, "pa") && ft_strequ(last_oper, "pb"))
		return (1);
	if (ft_strequ(oper, "ra") && ft_strequ(last_oper, "rra"))
		return (1);
	if (ft_strequ(oper, "rb") && ft_strequ(last_oper, "rrb"))
		return (1);
	if (ft_strequ(oper, "rr") && ft_strequ(last_oper, "rrr"))
		return (1);
	if (ft_strequ(oper, "rra") && ft_strequ(last_oper, "ra"))
		return (1);
	if (ft_strequ(oper, "rrb") && ft_strequ(last_oper, "rb"))
		return (1);
	if (ft_strequ(oper, "rrr") && ft_strequ(last_oper, "rr"))
		return (1);
	if (ft_strequ(oper, "sa") && ft_strequ(last_oper, "sa"))
		return (1);
	if (ft_strequ(oper, "sb") && ft_strequ(last_oper, "sb"))
		return (1);
	return (0);
}

static int	is_redundant_rotation(char *oper, char *last_oper)
{
	if (ft_strequ(oper, "ra") && 
		(ft_strequ(last_oper, "rb") || ft_strequ(last_oper, "rrr")))
		return (1);	
	if (ft_strequ(oper, "rb") && 
		(ft_strequ(last_oper, "ra") || ft_strequ(last_oper, "rrr")))
		return (1);
	if (ft_strequ(oper, "rr") && 
		(ft_strequ(last_oper, "rra") || ft_strequ(last_oper, "rrb")))
		return (1);
	if (ft_strequ(oper, "rra") && 
		(ft_strequ(last_oper, "rrb") || ft_strequ(last_oper, "rr")))
		return (1);
	if (ft_strequ(oper, "rrb") && 
		(ft_strequ(last_oper, "rra") || ft_strequ(last_oper, "rr")))
		return (1);
	if (ft_strequ(oper, "rrr") && 
		(ft_strequ(last_oper, "ra") || ft_strequ(last_oper, "rb")))
		return (1);
	return (0);
}

static int	is_redundant_swap(char *oper, char *last_oper)
{
	if (ft_strequ(oper, "sa") &&
		(ft_strequ(last_oper, "sb") || ft_strequ(last_oper, "ss")))
		return (1);
	if (ft_strequ(oper, "sb") &&
		(ft_strequ(last_oper, "sa") || ft_strequ(last_oper, "ss")))
		return (1);
	if (ft_strequ(oper, "ss") &&
		(ft_strequ(last_oper, "sa") || ft_strequ(last_oper, "sb")))
		return (1);
	return (0);
}

static int	is_nonsensical(const t_state *parent, char *oper)
{
	char	*last_oper;

	if (parent->trace->last == 0)
		return (0);
	last_oper = parent->trace->last->data;
	if (is_backtracking(oper, last_oper) ||
		is_redundant_rotation(oper, last_oper) ||
		is_redundant_swap(oper, last_oper))
		return (1);
	return (0);
}

int 		succeed_state(const t_state *parent, t_state **child, char *oper)
{
	int	rc;

	if (is_nonsensical(parent, oper))
		return (-1);
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
