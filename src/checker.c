/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:48:04 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:28:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;
	char	*oper;

	if (argc < 2)
		return (1);
	new_stack(&stackA);
	new_stack(&stackB);
	ps_tab2stack(++argv, stackA);
	while (1)
	{
		if (get_next_line(0, &oper) < 0)
			ps_exit("Malloc error\n", 2);
		if (ft_strequ(oper, ""))
			break ;
		perform_operation(&stackA, &stackB, oper);
		free(oper);
	}
	if (issorted_stack(stackA) && stackB->size == 0)
		ps_exit("OK\n", 0);
	ps_exit("KO\n", 0);
}
