/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:55:36 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:07:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	search_stack(const t_stack *stack, int num)
{
	t_link	*link;
	int		i;

	i = 0;
	link = stack->start;
	while (link)
	{
		if (link->value == num)
			return (i);
		i = i + 1;
		link = link->next;
	}
	return (-1);
}
