/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isset_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:28:08 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 03:24:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	isset_stack(const t_stack *stack)
{
	t_link	*ili;
	t_link	*jli;

	if (stack->size < 2)
		return (1);
	ili = stack->start;
	while (ili->next)
	{
		jli = ili->next;
		while (jli)
		{
			if (jli->value == ili->value)
				return (0);
			jli = jli->next;
		}
		ili = ili->next;
	}
	return (1);
}
