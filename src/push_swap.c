/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:29:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc < 2)
		return (1);
	new_stack(&stackA);
	new_stack(&stackB);
	ps_tab2stack(++argv, stackA);
	set_verbose(1);
	if (stackA->size <= 6)
		simple_sort(stackA, stackB);
	else
		advanced_sort(stackA, stackB);
}
