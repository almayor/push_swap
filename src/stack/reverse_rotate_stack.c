/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:09:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:48:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->end->next = stack->start;
	stack->start->previous = stack->end;
	stack->end = stack->end->previous;
	stack->start = stack->start->previous;
	stack->end->next = 0;
	stack->start->previous = 0;
}
