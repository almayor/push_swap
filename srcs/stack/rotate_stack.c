/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:09:00 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:28:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return (-1);
	stack->end->next = stack->start;
	stack->start->previous = stack->end;
	stack->start = stack->start->next;
	stack->end = stack->end->next;
	stack->end->next = 0;
	stack->start->previous = 0;
	return (0);
}
