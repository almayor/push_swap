/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:25:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 07:27:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"
#include "libft.h"

int	perform_operation(t_stack *stackA, t_stack *stackB, char *oper)
{
	int					i;
	static t_operation	dispatch_table[] = {
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
		(t_operation){ .name = "rrr", .function = perform_rrr }};

	ft_printf("%s\n", oper);
	i = 0;
	while (i < 11)
	{
		if (ft_strequ(dispatch_table[i].name, oper))
			return (dispatch_table[i].function(stackA, stackB));
		i++;
	}
	return (1);
}
