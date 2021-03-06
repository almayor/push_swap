/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/05/24 07:25:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_operations(t_stack *st_a, t_stack *st_b)
{
	char	*oper;

	while (get_next_line(0, &oper))
	{
		perform_operation(st_a, st_b, oper);
		if (errno)
			return (errno);
		free(oper);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	st_a;
	t_stack	st_b;

	if (argc < 2)
		return (0);
	new_stack(&st_a);
	new_stack(&st_b);
	if (ft_strequ(*(++argv), "-v"))
	{
		++argv;
		set_debug(1);
	}
	if (ps_tab2stack(argv, &st_a) ||
		process_operations(&st_a, &st_b))
	{
		free_stack(&st_a);
		free_stack(&st_b);
		ps_exit(errno);
	}
	if (issorted_stack(&st_a) && st_b.size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&st_a);
	free_stack(&st_b);
}
