/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:47:14 by unite             #+#    #+#             */
/*   Updated: 2020/02/23 04:19:39 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

void	print_trace(t_stack *stackA, t_stack *stackB, char *oper)
{
	t_link		*linkA;
	t_link		*linkB;
	int			valueA;
	int			valueB;

	if (oper)
		ft_printf("---------------------------------------\nExec %s:\n", oper);
	else
		ft_printf("---------------------------------------\nInit\n");
	linkA = stackA->start;
	linkB = stackB->start;
	while (linkA || linkB)
	{
		valueA = linkA ? linkA->value : 0;
		valueB = linkB ? linkB->value : 0;
		ft_printf("%1.0d %1.0d\n", valueA, valueB);
		linkA = linkA ? linkA->next : 0;
		linkB = linkB ? linkB->next : 0;
	}
	ft_printf("_ _\na b\n=======================================\n");
}
