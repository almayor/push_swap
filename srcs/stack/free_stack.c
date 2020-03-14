/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:10:27 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 12:55:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int free_stack(t_stack *stack)
{
	t_link	*link;

	if (!stack)
		return (1);
	while (stack->start)
	{
		link = stack->start->next;
		free(stack->start);
		stack->start = link;
	}
	free(stack);
	return (0);
}
