/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 11:34:26 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 12:58:03 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	copy_stack(const t_stack *stackA, t_stack **stackB)
{
	t_link	*linkA;
	t_link	*linkB;

	if (new_stack(stackB))
		return (1);
	linkA = stackA->first;
	while (linkA)
	{
		if (!(linkB = malloc(sizeof(t_link))))
		{
			free_stack(*stackB);
			return (1);
		}
		linkB->value = linkA->value;
		push_stack(*stackB, linkB);
		linkA = linkA->next;
	}
	return (0);
}
