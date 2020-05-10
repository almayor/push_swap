/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:24:28 by unite             #+#    #+#             */
/*   Updated: 2020/03/18 09:46:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     sort_stackA(t_stack *stackA, t_stack *stackB)
{
    int max;

    max_stack(stackA, stackA->size, &max);
    if (stackA->start->value == max)
        perform_operation(stackA, stackB, "ra");
    if (stackA->size > 2 && stackA->start->next->value == max)
        perform_operation(stackA, stackB, "rra");
    if (stackA->start->value > stackA->start->next->value)
        perform_operation(stackA, stackB, "sa");
    return (0);
}

static int     sort_stackB(t_stack *stackA, t_stack *stackB)
{
    int min;

    min_stack(stackB, stackA->size, &min);
    if (stackB->start->value == min)
        perform_operation(stackA, stackB, "rb");
    if (stackB->size > 2 && stackB->start->next->value == min)
        perform_operation(stackA, stackB, "rrb");
    if (stackB->start->value < stackB->start->next->value)
        perform_operation(stackA, stackB, "sb");
    return (0);
}

static int      split_stackA(t_stack *stackA, t_stack *stackB, int filter)
{
   int  i;
   int 	n;

   i = 0;
   n = stackA->size;
   while (i < n)
   {
       if (stackA->start->value <= filter)
           perform_operation(stackA, stackB, "pb");
       else
           perform_operation(stackA, stackB, "ra");
       i++;
   }
   return (0);
}

static int      merge_stacks(t_stack *stackA, t_stack *stackB)
{
   while (stackB->start)
       perform_operation(stackA, stackB, "pa");
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

int         simple_sort(t_stack *stackA, t_stack *stackB)
{
   int  avg;

   if (stackA->size < 2)
       return (0);
   if (stackA->size <= 3)
   {
	   sort_stackA(stackA, stackB);
	   return (0);
   }
   avg_stack(stackA, stackA->size, &avg);
   split_stackA(stackA, stackB, avg);
   sort_stackA(stackA, stackB);
   sort_stackB(stackA, stackB);
   merge_stacks(stackA, stackB);
   return (0);
}

int         advanced_sort(t_stack *stackA, t_stack *stackB)
{
    return (0);
}

int 		main(int argc, char **argv)
{
    t_stack		stackA;
    t_stack		stackB;

    if (argc < 2)
        return (1);
    argv += 1;
    new_stack(&stackA);
    new_stack(&stackB);
    if (process_arguments(&stackA, argv) ||
        (stackA.size <= 6 && simple_sort(&stackA, &stackB)) ||
        (stackA.size > 6 && advanced_sort(&stackA, &stackB)))
        ft_dprintf(2, "Error");
    print_stack(&stackA);
    print_stack(&stackB);
    free_stack(&stackA);
    free_stack(&stackB);
    return (0);
}
