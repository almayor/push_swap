/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 18:39:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_operations(t_stack *st_a, t_stack *st_b)
{
	char	*oper;

	while (get_next_line(0, &oper))
	{
		if (errno)
			return (errno);
		if (ft_strequ(oper, ""))
			return (0);
		perform_operation(st_a, st_b, oper);
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
	if (ps_tab2stack(++argv, &st_a) ||
		process_operations(&st_a, &st_b))
	{
		free_stack(&st_a);
		free_stack(&st_b);
		ps_exit(errno);
	}
	if (issorted_stack(&st_a) && st_b.size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(&st_a);
	free_stack(&st_b);
}
