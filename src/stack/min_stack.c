/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:56:45 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:37:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

int	min_stack(const t_stack *stack)
{
	t_link	*link;
	int		min;

	min = INT_MAX;
	link = stack->start;
	while (link)
	{
		if (link->value < min)
			min = link->value;
		link = link->next;
	}
	return (min);
}
