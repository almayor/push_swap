/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:17:43 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 06:13:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_arguments(t_stack *stack, char **argv)
{
	int	value;

	while (*argv)
	{
		if (!(is_numeric_str(*argv)) ||
			ft_atoi2(*argv, &value) ||
			append_stack(stack, value))
			return (1);
		argv += 1;
	}
	if (has_duplicates_stack(stack))
		return (1);
	return (0);
}

static int	show_trace(t_queue *trace)
{
	char	*oper;

	while (dequeue_queue(trace, &oper) == 0)
	{
		ft_dprintf(1, "%s\n", oper);
		free(oper);
	}
	return (0);
}

int 		main(int argc, char **argv)
{
	t_queue	*trace;
	t_stack	*stack;

	if (argc < 2)
		return (1);
	argv += 1;
	if (new_stack(&stack) ||
		process_arguments(stack, argv) ||
		A_search(stack, &trace))
		ft_dprintf(2, "Error\n");
	else
	{
		show_trace(trace);
		free_queue(trace);
	}
	free_stack(stack);
	return (0);
}
