/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:09:28 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:28:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	reverse_rotate_stack(t_stack *stack)
{
	if (!stack->start || !stack->end || stack->start == stack->end)
		return (-1);
	stack->end->next = stack->start;
	stack->start->previous = stack->end;
	stack->end = stack->end->previous;
	stack->start = stack->start->previous;
	stack->end->next = 0;
	stack->start->previous = 0;
	return (0);
}
