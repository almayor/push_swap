/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:25:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/17 05:00:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			g_verbose;

static t_operation	g_dispatch_table[] = {
	(t_operation){ .name = "sa", .fun = perform_sa },
	(t_operation){ .name = "sb", .fun = perform_sb },
	(t_operation){ .name = "ss", .fun = perform_ss },
	(t_operation){ .name = "pa", .fun = perform_pa },
	(t_operation){ .name = "pb", .fun = perform_pb },
	(t_operation){ .name = "ra", .fun = perform_ra },
	(t_operation){ .name = "rb", .fun = perform_rb },
	(t_operation){ .name = "rr", .fun = perform_rr },
	(t_operation){ .name = "rra", .fun = perform_rra },
	(t_operation){ .name = "rrb", .fun = perform_rrb },
	(t_operation){ .name = "rrr", .fun = perform_rrr },
};

void				set_verbose(int code)
{
	g_verbose = code;
}

void				perform_operation(t_stack *stack_a, t_stack *stack_b,
									char *oper)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(g_dispatch_table[i].name, oper))
		{
			if (g_verbose)
				ft_putendl(oper);
			g_dispatch_table[i].fun(stack_a, stack_b);
			return ;
		}
		i++;
	}
	errno = EINVAL;
}
