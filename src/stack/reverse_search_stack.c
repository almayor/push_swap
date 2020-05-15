/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_search_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:56:15 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:35:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	reverse_search_stack(const t_stack *stack, int num, int control)
{
	t_link	*link;
	int		i;

	i = 0;
	link = stack->end;
	while (link)
	{
		if ((control > 0 && link->value >= num) ||
			(control < 0 && link->value <= num) ||
			(control == 0 && link->value == num))
			return (i);
		i++;
		link = link->previous;
	}
	return (-1);	
}
