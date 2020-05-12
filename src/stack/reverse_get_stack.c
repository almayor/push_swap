/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_get_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:46:59 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 21:47:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_get_stack(t_stack *stack, int index)
{
	t_link	*link;

	if (index >= stack->size)
		return (-1);
	link = stack->end;
	while (index-- > 0)
		link = link->previous;
	return (link->value);
}
