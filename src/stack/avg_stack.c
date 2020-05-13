/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avg_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:56:18 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:30:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	avg_stack(const t_stack *stack)
{
	t_link		*link;
	long double	avg;

	avg = 0;
	link = stack->start;
	while (link)
	{
		avg += link->value / stack->size;
		link = link->next;
	}
	return (avg);
}
