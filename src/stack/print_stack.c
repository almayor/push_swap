/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:17:26 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:35:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stack(const t_stack *stack)
{
	t_link	*link;

	link = stack->start;
	if (!link)
		return ;
	ft_printf("Forward links: %d", link->value);
	while ((link = link->next))
		ft_printf("->%d", link->value);
	ft_printf("\n");
	link = stack->end;
	ft_printf("Backward links: %d", link->value);
	while ((link = link->previous))
		ft_printf("<-%d", link->value);
	ft_printf("\n");
}
