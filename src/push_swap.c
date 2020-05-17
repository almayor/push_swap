/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/17 19:04:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	sa;
	t_stack	sb;

	if (argc < 2)
		return (0);
	ft_printf("NBATCHES = %d\n", NBATCHES);
	set_verbose(1);
	new_stack(&sa);
	new_stack(&sb);
	if (!ps_tab2stack(++argv, &sa) && !ps_index_stack(&sa))
	{
		if (sa.size <= 6)
			simple_sort(&sa, &sb);
		else
			advanced_sort(&sa, &sb);
	}
	free_stack(&sa);
	free_stack(&sb);
	ps_exit(errno);
}
