/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:10:27 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 19:12:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	free_stack(t_stack *stack)
{
	t_ilink	*link;

	if (!stack)
		return (0);
	while (stack->start)
	{
		link = stack->start->next;
		free(stack->start);
		stack->start = link;
	}
	free(stack);
	return (0);
}
