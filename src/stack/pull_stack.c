/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:07:35 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 22:31:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	pull_stack(t_stack *stack)
{
	t_link	*link;
	int		value;

	link = stack->start;
	value = link->value;
	stack->start = link->next;
	if (stack->size > 1)
		stack->start->previous = 0;
	if (stack->size == 0)
		stack->end = 0;
	free(link);
	stack->size -= 1;
	return (value);
}
