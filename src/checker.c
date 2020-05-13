/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 17:41:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_operations(t_stack *stackA, t_stack *stackB)
{
	char	*oper;

	while (1)
	{
		if (errno || get_next_line(0, &oper) < 0)
			return (errno);
		if (ft_strequ(oper, ""))
			return (0) ;
		perform_operation(&stackA, &stackB, oper);
		free(oper);
	}
}

int main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc < 2)
		return (0);
	new_stack(&stackA);
	new_stack(&stackB);
	if (ps_tab2stack(++argv, &stackA) ||
		process_operations(&stackA, &stackB))
	{
		free_stack(&stackA);
		free_stack(&stackB);
		ps_exit(errno);
	}
	if (issorted_stack(&stackA) && stackB.size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(&stackA);
	free_stack(&stackB);
}
