/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:10:27 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:25:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack *stack)
{
	t_link	*link;

	while (stack->start)
	{
		link = stack->start->next;
		free(stack->start);
		stack->start = link;
	}
	stack->size = 0;
}
