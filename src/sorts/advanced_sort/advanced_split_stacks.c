/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_split_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:32:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/23 18:25:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nconflicts(const t_stack *st, int i, const int *split_schema)
{
	t_link	*li;
	int		val;
	int		j;
	int 	k;
	int		nconfl;

	li = st->start;
	val = get_stack(st, i);
	j = 0;
	k = search_stack(st, 1);
	nconfl = 0;
	while (li)
	{
		if (split_schema[li->value] == 0)
		{
			if ((j < k && i < k && j < i && li->value > val) ||
				(j > k && i > k && j > i && li->value < val) ||
				(j < k && i > k && li->value < val) ||
				(j > k && i < k && li->value > val))
				nconfl++;
		}
		li = li->next;
		j++;
	}
	return (nconfl);
}

static int	has_conflicts(t_stack *st, int *split_schema)
{
	t_link	*li1;
	t_link	*li2;

	li1 = st->start;
	while (li1 && split_schema[li1->value])
		li1 = li1->next;
	while (1)
	{
		li2 = li1->next;
		while (li2 && split_schema[li2->value])
			li2 = li2->next;
		if (!li2)
			break ;
		if (li2->value != 1 && li1->value > li2->value)
			return (1);
		li1 = li2;
	}
	li2 = st->start;
	while (li2 && split_schema[li2->value])
		li2 = li2->next;
	if (li2->value != 1 && li1->value > li2->value)
		return (1);
	return (0);
}

static int	get_next_pushed(const t_stack *st, const int *split_schema)
{
	int	i;
	int	push_val;
	int	push_val_nconfl;
	int	val;
	int	val_nconfl;

	push_val_nconfl = 0;
	push_val = 0;
	i = 0;
	while (i < st->size)
	{
		val = get_stack(st, i);
		if (!split_schema[val])
		{
			val_nconfl = get_nconflicts(st, i, split_schema);
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

void		advanced_split_stacks(t_stack *st_a, t_stack *st_b)
{
	int	*split_schema;
	int	push_val;
	int	i;

	if (!(split_schema = ft_calloc(st_a->size + 1, sizeof(int))))
	{
		errno = ENOMEM;
		return ;
	}
	while (has_conflicts(st_a, split_schema))
	{
		push_val = get_next_pushed(st_a, split_schema);
		split_schema[push_val] = 1;
	}
	i = st_a->size;
	while (errno == 0 && i-- > 0)
	{
		if (split_schema[st_a->start->value])
			perform_operation(st_a, st_b, "pb");
		else
			perform_operation(st_a, st_b, "ra");
	}
	free(split_schema);
}
