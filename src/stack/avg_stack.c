//
// Created by almayor on 26.03.2020.
//

#include "stack.h"

int     avg_stack(t_stack *stack)
{
    t_link  	*link;
    long double	avg;

    avg = 0;
    link = stack->start;
    while (link)
    {
        avg += link->value / stack->size;
        link = link->next;
    }
    return (avg);
}


