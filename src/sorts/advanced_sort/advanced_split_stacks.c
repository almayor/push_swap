/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_split_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:25:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nconflicts(const t_stack *st, int i, const int *is_pushed)
{
	int	val1;
	int	val2;
	int	j;
	int	jumped2top;
	int	nconfl;

	val1 = get_stack(st, i);
	jumped2top = 0;
	j = 1;
	nconfl = 0;
	while (j < st->size)
	{
		val2 = get_stack(st, (i + j) % st->size);
		if (!is_pushed[val2])
		{
			if (val2 == 1)
				jumped2top = 1;
			else if (!jumped2top && val2 < val1)
				nconfl++;
			else if (jumped2top && val2 > val1)
				nconfl++;
		}
		j++;
	}
	return (nconfl);
}

static int	has_conflicts(t_stack *st, int *is_pushed)
{
	int i = 0;

	while (i < st->size)
	{
		if (!is_pushed[get_stack(st, i)] && get_nconflicts(st, i, is_pushed))
			return (1)
		i++;
	}
	return (0);
}

static int	get_next_pushed(const t_stack *st, const int *is_pushed)
{
	int	i;
	int	push_val;
	int	push_val_nconfl;
	int	val;
	int	val_nconfl;

	push_val_nconfl = 0;
	i = 0;
	while (i < st->size)
	{
		val = get_stack(st, i);
		if (!is_pushed[val])
		{
			val_nconfl = count_conflicts(st, i, is_pushed);
			if (val_nconfl > push_val_nconfl)
			{
				push_val_nconfl = val_nconfl;
				push_val = val;
			}
		}
		i++;
	}
	return (push_val);
}

void		advanced_split_stack(t_stack *st_a, t_stack *st_b)
{
	int	*is_pushed;
	int	push_val;
	int	i;

	if (!(is_pushed = ft_calloc(st_a->size + 1, sizeof(int))))
	{
		errno = ENOMEM;
		return ;
	}
	while (has_conflicts(st_a, is_pushed))
	{
		push_val = next_to_remove(st_a, is_pushed);
		is_pushed[push_val] = 1;
	}
	i = st_a->size;
	while (errno == 0 && i-- > 0)
	{
		if (is_removed[st_a->start->value])
			perform_operation(st_a, st_b, "pb");
		else
			perform_operation(st_a, st_b, "ra");
	}
	free(is_pushed);
}
