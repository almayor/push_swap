/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:42:53 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 22:48:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_index_stack(t_stack **stack)
{
	t_stack	index_stack;
	t_link	*ilink;
	t_link	*jlink;
	int		index;

	new_stack(&index_stack);
	ilink = *stack;
	while (ilink)
	{
		jlink = *stack;
		index = 0;
		while (jlink)
		{
			if (ilink->value <= jlink->value)
				++index;
			jlink = jlink->next;
		}
		push_stack(index_stack, index);
		ilink = ilink->next;
	}
	free_stack(*stack);
	*stack = index_stack;
}
