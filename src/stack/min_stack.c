//
// Created by almayor on 26.03.2020.
//

#include "stack.h"
#include <limits.h>

int     min_stack(t_stack *stack)
{
    t_link  *link;
    int  	min;

    min = INT_MAX;
    link = stack->start;
    while (link)
    {
        if (link->value < min)
        	min = link->value;
        link = link->next;
    }
    return (min);
}
