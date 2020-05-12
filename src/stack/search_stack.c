/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:55:36 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 21:31:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					search_stack(t_stack *stack, int num, int control)
{
	t_link	*link;
	int		i;

	i = 0;
	link = stack->start;
	while (link)
	{
		if ((control > 0 && link->value >= num) ||
			(control < 0 && link->value =< num) ||
			(control == 0 && link->value == num))
			return (i);
		i++;
		link = link->next;
	}
	return (-1);
}
