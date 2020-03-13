/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:07:35 by unite             #+#    #+#             */
/*   Updated: 2020/02/23 03:57:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	pull_stack(t_stack *stack, t_link **link)
{
	if (!stack)
		return (1);
	if (!stack->start)
	{
		*link = 0;
		return (0);
	}
	*link = stack->start;
	stack->start->previous = 0;
	stack->start = stack->start->next;
	if (stack->start == stack->end)
		stack->end = 0;
	return (0);
}
