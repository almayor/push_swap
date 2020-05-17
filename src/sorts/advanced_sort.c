/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 00:43:27 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nra(t_stack *stack_a, int batch_ceil)
{
	int	ifirst;
	int	ilast;

	ifirst = search_stack(stack_a, batch_ceil, -1, 0);
	ilast = search_stack(stack_a, batch_ceil, -1, 1);
	if (ifirst <= stack_a->size - 1 - ilast)
		return (ifirst);
	else
		return (ilast);
}

static int	get_nrb(t_stack *stack_b, int value)
{
	if (stack_b->size < 2)
		return (0);
	if (max_stack(stack_b) < value || min_stack(stack_b) > value)
		return (search_stack(stack_b, max_stack(stack_b), 0, 0));
	if (stack_b->start->value < value && stack_b->end->value > value)
		return (0);
	if (stack_b->start->value > value)
		return (search_stack(stack_b, value, -1, 0));
	else
		return (search_stack(stack_b, value, 1, 1) + 1);
}

static void	push_once(t_stack *stack_a, t_stack *stack_b, int batch_ceil)
{
	int	n_ra;
	int	n_rb;
	int	n_rra;
	int	n_rrb;

	n_ra = get_nra(stack_a, batch_ceil);
	n_rb = get_nrb(stack_b, get_stack(stack_a, n_ra));
	n_rra = stack_a->size - n_ra;
	n_rrb = stack_b->size - n_rb;
	if (ft_max(n_ra, n_rb) <= ft_max(n_rra, n_rrb) &&
		ft_max(n_ra, n_rb) <= ft_min(n_ra, n_rra) + ft_min(n_rb, n_rrb))
		prepare_stacks_ra_rb(stack_a, stack_b, n_ra, n_rb);
	else if (ft_max(n_rra, n_rrb) <= ft_min(n_ra, n_rra) + ft_min(n_rb, n_rrb))
		prepare_stacks_rra_rrb(stack_a, stack_b, n_rra, n_rrb);
	else if (n_ra + n_rrb <= n_rb + n_rra)
		prepare_stacks_ra_rrb(stack_a, stack_b, n_ra, n_rrb);
	else
		prepare_stacks_rra_rb(stack_a, stack_b, n_rra, n_rb);
	perform_operation(stack_a, stack_b, "pb");
}

int			get_nbatches(int nvalues)
{
	if (nvalues <= 100)
		return (5);
	else
		return (5 * (1.25 - nvalues / 400.0) + 13 * (nvalues / 400.0 - 0.25));
}

void		advanced_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		nbatches;
	int		batchsize;
	int 	i;
	int		j;

	if (issorted_stack(stack_a))
		return ;
	nbatches = get_nbatches(stack_a->size);
	batchsize = stack_a->size > nbatches ? stack_a->size / nbatches : 1;
	i = 0;
	while (errno == 0 && i++ < nbatches - 1 && stack_a->size > 0)
	{
		j = 0;
		while (errno == 0 && j++ < batchsize)
			push_once(stack_a, stack_b, batchsize * i);
	}
	while (errno == 0 && stack_a->size > 0)
		push_once(stack_a, stack_b, INT_MAX);
	while (errno == 0 && stack_b->start->value != stack_b->size)
		perform_operation(stack_a, stack_b, "rrb");
	while (errno == 0 && stack_b->start)
		perform_operation(stack_a, stack_b, "pa");
}
