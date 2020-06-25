/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 07:14:22 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 15:58:11 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stacks(t_stack *st_a, t_stack *st_b)
{
	t_link	*li_a;
	t_link	*li_b;

	li_a = st_a->start;
	li_b = st_b->start;
	ft_printf("|-----------|-----------|\n");
	ft_printf("|  stack A  |  stack B  |\n");
	ft_printf("|-----------|-----------|\n");
	while (li_a || li_b)
	{
		if (li_a)
			ft_printf("|   %-5d   ", li_a->value);
		else
			ft_printf("|           ");
		if (li_b)
			ft_printf("|   %-5d   |\n", li_b->value);
		else
			ft_printf("|           |\n");
		ft_printf("|-----------|-----------|\n");
		li_a = li_a ? li_a->next : NULL;
		li_b = li_b ? li_b->next : NULL;
	}
}
