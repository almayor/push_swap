/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:07:16 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:36:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	append_stack(t_stack *stack, int value)
{
	t_ilink	*link;

	if (!(link = malloc(sizeof(t_ilink))))
		return (1);
	link->value = value;
	link->next = 0;
	link->previous = stack->end;
	stack->end = link;
	if (link->previous)
		link->previous->next = link;
	if (!stack->start)
		stack->start = link;
	return (0);
}
