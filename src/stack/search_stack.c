/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:55:36 by unite             #+#    #+#             */
/*   Updated: 2020/05/17 02:24:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	search_stack(const t_stack *stack, int num, int comp, int order)
{
	t_link	*link;
	int		i;

	i = order ? stack->size - 1 : 0;
	link = order ? stack->end : stack->start;
	while (link)
	{
		if ((comp > 0 && link->value >= num) ||
			(comp < 0 && link->value <= num) ||
			(comp == 0 && link->value == num))
			return (i);
		i = order ? i - 1 : i + 1;
		link = order ? link->previous : link->next;
	}
	return (-1);
}
