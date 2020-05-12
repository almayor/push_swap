/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:25:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:20:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int			g_verbose;

static t_operation	g_dispatch_table[] = {
	(t_operation){ .name = "sa", .function = perform_sa },
	(t_operation){ .name = "sb", .function = perform_sb },
	(t_operation){ .name = "ss", .function = perform_ss },
	(t_operation){ .name = "pa", .function = perform_pa },
	(t_operation){ .name = "pb", .function = perform_pb },
	(t_operation){ .name = "ra", .function = perform_ra },
	(t_operation){ .name = "rb", .function = perform_rb },
	(t_operation){ .name = "rr", .function = perform_rr },
	(t_operation){ .name = "rra", .function = perform_rra },
	(t_operation){ .name = "rrb", .function = perform_rrb },
	(t_operation){ .name = "rrr", .function = perform_rrr },
	(t_operation){ .name = NULL, .function = NULL }

};

void				set_verbose(int code)
{
	g_verbose = code;
}

void				perform_operation(t_stack *stackA, t_stack *stackB, char *oper)
{
	int	i;

	i = 0;
	while (g_dispatch_table[i].name)
	{
		if (ft_strequ(g_dispatch_table[i].name, oper))
		{
			if (g_verbose)
				ft_putendl("%s\n", oper);
			g_dispatch_table[i].function(stackA, stackB);
			return ;
		}
		i++;
	}
	ps_exit("Error\n", 1);
}
