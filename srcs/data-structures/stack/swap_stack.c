/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:08:41 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:21:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap_stack(t_stack *stack)
{
	if (!stack->start || !stack->end || stack->start == stack->end)
		return (-1);
	stack->start->previous = stack->start->next;
	stack->start->next = stack->start->next->next;
	stack->start->previous->next = stack->start;
	stack->start = stack->start->previous;
	stack->start->previous = 0;
	if (stack->start->next->next)
		stack->start->next->next->previous = stack->start->next;
	if (stack->start == stack->end)
		stack->end = stack->start->next;
	return (0);
}
