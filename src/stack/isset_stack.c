/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isset_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:28:08 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 15:13:24 by unite            ###   ########.fr       */
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
		jli = ili;
		while (jli->next)
		{
			if (jli->value == jli->next->value)
				return (0);
			jli = jli->next;
		}
		ili = ili->next;
	}
	return (1);
}
