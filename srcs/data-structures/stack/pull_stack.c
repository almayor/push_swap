/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:07:35 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 18:22:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	pull_stack(t_stack *stack, int *value)
{
	t_ilink	*link;

	if (!stack->start)
		return (-1);
	link = stack->start;
	*value = link->value;
	stack->start = link->next;
	if (stack->start)
		stack->start->previous = 0;
	else
		stack->end = 0;
	free(link);
	return (0);
}
