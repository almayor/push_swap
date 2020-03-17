/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 11:34:26 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:36:27 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	copy_stack(const t_stack *stackA, t_stack **stackB)
{
	t_ilink	*linkA;

	if (new_stack(stackB))
		return (1);
	linkA = stackA->start;
	while (linkA)
	{
		if (append_stack(*stackB, linkA->value))
		{
			free_stack(*stackB);
			return (1);
		}
		linkA = linkA->next;
	}
	return (0);
}
