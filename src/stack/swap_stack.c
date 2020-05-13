/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:08:41 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:26:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_stack(t_stack *stack)
{
	stack->start->previous = stack->start->next;
	stack->start->next = stack->start->next->next;
	stack->start->previous->next = stack->start;
	stack->start = stack->start->previous;
	stack->start->previous = 0;
	if (stack->size > 2)
		stack->start->next->next->previous = stack->start->next;
	if (stack->size == 2)
		stack->end = stack->start->next;
}
