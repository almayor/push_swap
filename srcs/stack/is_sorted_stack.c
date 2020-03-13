/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:52:31 by unite             #+#    #+#             */
/*   Updated: 2020/02/25 19:44:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted_stack(const t_stack *stack)
{
	t_link *link;

	if (!stack->start)
		return (-1);
	link = stack->start;
	while (link->next)
	{
		if (link->value >= link->next->value)
			return (0);
		link = link->next;
	}
	return (1);
}
