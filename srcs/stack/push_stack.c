/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:03:54 by unite             #+#    #+#             */
/*   Updated: 2020/02/23 03:58:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_stack(t_stack *stack, t_link *link)
{
	if (!stack)
		return (1);
	if (!link)
		return (0);
	link->next = stack->start;
	link->previous = 0;
	stack->start = link;
	if (link->next)
		link->next->previous = link;
	if (!stack->end)
		stack->end = link->next;
	return (0);
}
