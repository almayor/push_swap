/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:03:54 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:31:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <errno.h>
#include <stdlib.h>

int	push_stack(t_stack *stack, int value)
{
	t_link	*link;

	if (!(link = malloc(sizeof(t_link))))
		return ((errno = ENOMEM));
	link->value = value;
	link->next = stack->start;
	link->previous = 0;
	if (stack->size > 0)
		stack->start->previous = link;
	if (stack->size == 0)
		stack->end = link;
	stack->start = link;
	stack->size += 1;
	return (0);
}
