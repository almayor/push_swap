/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 03:16:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*oper;

	while (get_next_line(0, &oper))
	{
		if (errno)
			return (errno);
		if (ft_strequ(oper, ""))
			return (0);
		perform_operation(stack_a, stack_b, oper);
		free(oper);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	new_stack(&stack_a);
	new_stack(&stack_b);
	if (ps_tab2stack(++argv, &stack_a) ||
		process_operations(&stack_a, &stack_b))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		ps_exit(errno);
	}
	if (issorted_stack(&stack_a) && stack_b.size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
