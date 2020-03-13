/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:17:43 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 07:49:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "utils.h"
#include "sorting.h"
#include "operations.h"

int main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc < 2)
		return (1);
	new_stack(&stackA);
	new_stack(&stackB);
	argv += 1;
	if (arguments_to_stack(&stackA, argv))
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	print_stack(&stackA);
	insertion_sort(&stackA, &stackB, argc - 1);
	print_stack(&stackA);
	return (0);
}
