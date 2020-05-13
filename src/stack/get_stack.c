/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:45:20 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:28:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	get_stack(const t_stack *stack, int index)
{
	t_link	*link;

	if (index >= stack->size)
		return (-1);
	link = stack->start;
	while (index-- > 0)
		link = link->next;
	return (link->value);
}
