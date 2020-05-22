/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:52:31 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:33:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	issorted_stack(const t_stack *stack)
{
	t_link *link;

	if (stack->size < 2)
		return (1);
	link = stack->start;
	while (link->next)
	{
		if (link->value >= link->next->value)
			return (0);
		link = link->next;
	}
	return (1);
}
