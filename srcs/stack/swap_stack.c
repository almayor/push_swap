/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:08:41 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 05:59:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap_stack(t_stack *stack)
{
	if (!stack)
		return (1);
	if (!stack->start || !stack->end)
		return (0);

	stack->start->previous = stack->start->next;
	stack->start->next = stack->start->next->next;
	stack->start->previous->next = stack->start;
	stack->start->next->previous = stack->start;
	stack->start = stack->start->previous;
	stack->start->previous = 0;
	if (stack->start == stack->end)
		stack->end = stack->start->next;
	return (0);
}
