/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 18:39:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	parse_A2B(t_stack *stackA, t_stack *stackB, int len)
{
	static int	reverse = 0;
	int			median;
	int			i;

	median = get_median(stackA, len);
	i = 0;
	while (i < len)
	{
		if (reverse && stackA->start->value < median)
			perform_operation(stackA, stackB, "pb");
		if (reverse)
			perform_operation(stackA, stackB, "rra");
		if (!reverse && stack->start->value > median)
			perform_operation(stackA, stackB, "pb");
		else
			perform_operation(stackA, stackB, "ra");
		i++;
	}
	reverse = !reverse;
}

void	parse_B2A(t_stack *stackA, t_stack *stackB, int len)
{
	static int	reverse = 0;
	int			median;
	int			i;

	median = get_median(stackA, len);
	i = 0;
	while (i < len)
	{
		if (reverse && stackA->start->value > median)
			perform_operation(stackA, stackB, "pa");
		if (reverse)
			perform_operation(stackA, stackB, "rrb");
		if (!reverse && stack->start->value < median)
			perform_operation(stackA, stackB, "pa");
		else
			perform_operation(stackA, stackB, "rb");
		i++;
	}
	reverse = !reverse;
}

void	merge_A2B(t_stack *stackA, t_stack *stackB, int len)
{
	static int	reverse = 1;
	int	i;

	i = 0;
	while (i < len / 2)
	{
		perform_operation(stackA, stackB, "pb");
		i++;
	}
	i = 0;
	while (reverse && i < len - len / 2)
	{
		perform_operation(stackA, stackB, "rrb");
		i++;
	}
	reverse = !reverse;
}

void	merge_B2A(t_stack *stackA, t_stack *stackB, int len)
{
	static int	reverse = 1;
	int	i;

	i = 0;
	while (i < len / 2)
	{
		perform_operation(stackA, stackB, "pa");
		i++;
	}
	i = 0;
	while (reverse && i < len - len / 2)
	{
		perform_operation(stackA, stackB, "rra");
		i++;
	}
	reverse = !reverse;
}

void	sortA(t_stack *stackA, t_stack *stackB, int len)
{
	if (len == 1)
		return ;
	parse_A2B(stackA, stackB, len);
	sortB(stackA, stackB, len / 2);
	sortA(stackA, stackB, len - len / 2);
	merge_B2A(stackA, stackB, len);
}

void	sortB(t_stack *stackA, t_stack *stackB, int len)
{
	if (len == 1)
		return ;
	parse_B2A(stackA, stackB, len);
	sortA(stackA, stackB, len / 2);
	sortB(stackA, stackB, len - len / 2);
	merge_A2B(stackA, stackB, len);
}
