/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_merge_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 04:34:25 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 18:41:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nra(const t_stack *st_a, int val)
{
	int		nra;
	t_link	*li;

	if (val > max_stack(st_a))
		return (search_stack(st_a, 1));
	if (val < st_a->start->value && val > st_a->end->value)
		return (0);
	nra = 1;
	li = st_a->start->next;
	while (li)
	{
		if (val < li->value && val > li->previous->value)
			return (nra);
		nra++;
		li = li->next;
	}
	return (-1);
}

static int	get_noper(int nra, int nrra, int nrb, int nrrb)
{
	if (ft_max(nra, nrb) < ft_max(nrra, nrrb) &&
		ft_max(nra, nrb) < ft_min(nra + nrrb, nrb + nrra))
		return (ft_max(nra, nrb));
	else if (ft_max(nrra, nrrb) < ft_min(nra + nrrb, nrb + nrra))
		return (ft_max(nrra, nrrb));
	else if (nra + nrrb < nrb + nrra)
		return (nra + nrrb);
	else
		return (nrb + nrra);
}

static int	get_next_pushed(const t_stack *st_a, const t_stack *st_b)
{
	int	nrb;
	int	nra;
	int	min_noper;
	int	min_noper_val;

	nrb = 0;
	min_noper = INT_MAX;
	while (nrb < st_b->size)
	{
		nra = get_nra(st_a, get_stack(st_b, nrb));
		if (min_noper > get_noper(nra, st_a->size - nra, nrb, st_b->size - nrb))
		{
			min_noper = get_noper(nra, st_a->size - nra, nrb, st_b->size - nrb);
			min_noper_val = get_stack(st_b, nrb);
		}
		nrb++;
	}
	return (min_noper_val);
}

static void	push_once(t_stack *st_a, t_stack *st_b, int push_val)
{
	int nrb;
	int	nra;
	int nrrb;
	int nrra;

	nrb = search_stack(st_b, push_val);
	nra = get_nra(st_a, push_val);
	nrrb = st_b->size - nrb;
	nrra = st_a->size - nra;
	if (ft_max(nra, nrb) < ft_max(nrra, nrrb) &&
		ft_max(nra, nrb) < ft_min(nra + nrrb, nrb + nrra))
		advanced_push_ra_rb(st_a, st_b, nra, nrb);
	else if (ft_max(nrra, nrrb) < ft_min(nra + nrrb, nrb + nrra))
		advanced_push_rra_rrb(st_a, st_b, nrra, nrrb);
	else if (nra + nrrb < nrb + nrra)
		advanced_push_ra_rrb(st_a, st_b, nra, nrrb);
	else
		advanced_push_rra_rb(st_a, st_b, nrra, nrb);
}

void		advanced_merge_stacks(t_stack *st_a, t_stack *st_b)
{
	int	push_val;
	int ra;
	int rra;

	while (errno == 0 && st_b->size > 0)
	{
		push_val = get_next_pushed(st_a, st_b);
		push_once(st_a, st_b, push_val);
	}
	ra = search_stack(st_a, 1);
	rra = st_a->size - ra;
	if (ra < rra)
	{
		while (ra-- > 0)
			perform_operation(st_a, st_b, "ra");
	}
	else
	{
		while (rra-- > 0)
			perform_operation(st_a, st_b, "rra");
	}
}
