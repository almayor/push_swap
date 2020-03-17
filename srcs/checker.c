/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 06:17:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_options(t_display *display, char **argv)
{
	display->verbose = 0;
	display->color = 0;
	while (**argv == '-')
	{
		if (ft_strequ(*argv, "-v"))
			display->verbose = 1;
		else if (ft_strequ(*argv, "-c"))
			display->color = 1;
		else
			return (1);
		argv += 1;
	}
	return (0);
}

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

static int	process_operators(t_stack *stackA, t_stack *stackB,
							  t_display *display)
{
	char	*oper;
	int		rc;

	while (1)
	{
		rc = get_next_line(0, &oper);
		if (rc == -1)
			return (1);
		if (rc == 0)
			return (0);
		if (ft_strequ(oper, ""))
		{
			free(oper);
			return (0);
		}
		if (perform_operation(stackA, stackB, oper))
		{
			free(oper);
			return (1);
		}
		show_graphics(stackA, stackB, oper, display);
		free(oper);
	}
}

int 		main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;
	t_display	display;

	if (argc < 2)
		return (1);
	argv += 1;
	stackA = 0;
	stackB = 0;
	if (new_stack(&stackA) ||
		new_stack(&stackB))
		ft_dprintf(2, "Error\n");
	else if (process_options(&display, argv) ||
			 process_arguments(stackA, argv) ||
			 process_operators(stackA, stackB, &display))
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
