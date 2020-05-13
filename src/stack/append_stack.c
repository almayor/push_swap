/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:07:16 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:30:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <errno.h>

int	append_stack(t_stack *stack, int value)
{
	t_link	*link;

	if (!(link = malloc(sizeof(t_link))))
		return ((errno = ENOMEM));
	link->value = value;
	link->next = 0;
	link->previous = stack->end;
	if (stack->size > 0)
		stack->end->next = link;
	if (stack->size == 0)
		stack->start = link;
	stack->end = link;
	stack->size += 1;
	return (0);
}
