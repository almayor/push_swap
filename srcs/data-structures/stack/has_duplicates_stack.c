/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:28:08 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 02:06:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	has_duplicates_stack(const t_stack *stack)
{
	t_ilink	*start;
	t_ilink	*current;

	if (!stack->start)
		return (0);
	start = stack->start;
	while (start->next)
	{
		current = start;
		while (current->next)
		{
			if (current->value == current->next->value)
				return (1);
			current = current->next;
		}
		start = start->next;
	}
	return (0);
}
