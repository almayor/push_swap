/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:42:53 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 19:40:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	switch_stacks(t_stack *stack1, t_stack *stack2)
{
	t_stack	tmp;

	tmp = *stack1;
	*stack1 = *stack2;
	*stack2 = tmp;
}

static int	get_index(t_stack *stack, int val)
{
	t_link *li;
	int		index;

	li = stack->start;
	index = 0;
	while (li)
	{
		if (li->value <= val)
			++index;
		li = li->next;
	}
	return (index);
}

int			ps_index_stack(t_stack *stack)
{
	t_stack	index_stack;
	t_link	*li;

	new_stack(&index_stack);
	li = stack->start;
	while (li)
	{
		if (append_stack(&index_stack, get_index(stack, li->value)))
		{
			free_stack(&index_stack);
			return ((errno = ENOMEM));
		}
		li = li->next;
	}
	switch_stacks(stack, &index_stack);
	free_stack(&index_stack);
	return (0);
}
