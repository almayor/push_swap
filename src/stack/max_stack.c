/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:56:18 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:30:40 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

int	max_stack(const t_stack *stack)
{
	t_link	*link;
	int		max;

	max = INT_MIN;
	link = stack->start;
	while (link)
	{
		if (link->value > max)
			max = link->value;
		link = link->next;
	}
	return (max);
}
