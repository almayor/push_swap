/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 12:59:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "utils.h"
#include "sorting.h"
#include "operations.h"
 
static int	process_arguments(t_stack *stack, char **argv)
{
	argv += 1;
	return (arguments_to_stack(stack, argv));
}

static int	process_operators(t_stack *stackA, t_stack *stackB)
{
	char	*oper;

	while (1)
	{
		if (get_next_line(0, &oper) < 0)
			return (1);
		if (ft_strequ(oper, ""))
			return (0);
		if (perform_operation(stackA, stackB, oper))
			return (1);
		free(oper);
	}
}

int 		main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	if (argc < 2)
		return (1);
	new_stack(&stackA);
	new_stack(&stackB);
	if (process_arguments(stackA, argv) ||
		process_operators(stackA, stackB))
		ft_dprintf(2, "Error\n");
	else if (is_sorted_stack(stackA) &&
			 is_empty_stack(stackB))
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	free_stack(stackA);
	free_stack(stackB);
	return (0);
}
