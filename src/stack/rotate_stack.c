/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:09:00 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 15:11:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_stack(t_stack *stack)
{
	stack->end->next = stack->start;
	stack->start->previous = stack->end;
	stack->start = stack->start->next;
	stack->end = stack->end->next;
	stack->end->next = 0;
	stack->start->previous = 0;
}
