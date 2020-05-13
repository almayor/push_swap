/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:10:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	sA;
	t_stack	sB;

	if (argc < 2)
		return (0);
	set_verbose(1);
	new_stack(&sA);
	new_stack(&sB);
	ps_tab2stack(++argv, &sA) ||
	ps_index_stack(&sA) ||
	(sA->size <= 6 && simple_sort(sA, sB)) ||
	(sA->size > 6 && advanced_sort(sA, sB));
	free_stack(&sA);
	free_stack(&sB);
	ps_exit(errno);
}
