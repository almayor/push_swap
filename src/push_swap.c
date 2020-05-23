/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/23 19:53:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	st_a;
	t_stack	st_b;

	if (argc < 2)
		return (0);
	set_verbose(1);
	new_stack(&st_a);
	new_stack(&st_b);
	if (!ps_tab2stack(++argv, &st_a) && !ps_index_stack(&st_a))
	{
		if (st_a.size <= 6)
			simple_sort(&st_a, &st_b);
		else
			advanced_sort(&st_a, &st_b);
	}
	free_stack(&st_a);
	free_stack(&st_b);
	ps_exit(errno);
}
