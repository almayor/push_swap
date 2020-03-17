/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:03:54 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:21:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_stack(t_stack *stack, int value)
{
	t_ilink	*link;

	if (!(link = malloc(sizeof(t_ilink))))
		return (1);
	link->value = value;
	link->next = stack->start;
	link->previous = 0;
	stack->start = link;
	if (link->next)
		link->next->previous = link;
	if (!stack->end)
		stack->end = stack->start;
	return (0);
}
