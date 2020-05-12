//
// Created by almayor on 26.03.2020.
//

#include "stack.h"
#include <limits.h>

int     max_stack(t_stack *stack)
{
    t_link  *link;
    int		max;

    max = INT_MIN;
	link = stack->start;
    while (link)
    {
        if (link->value > max)
            max = link->value;
        link = link->next;
    }
    return (max);
}
