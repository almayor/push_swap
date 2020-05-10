//
// Created by almayor on 26.03.2020.
//

#include "stack.h"

int     max_stack(t_stack *stack, size_t length, int *max)
{
    t_link  *link;
    size_t  i;

    if (length > stack->size || stack->size == 0 || length == 0)
        return (1);
    i = 1;
    link = stack->start;
    *max = link->value;
    while (i < length)
    {
        link = link->next;
        if (*max < link->value)
            *max = link->value;
        i++;
    }
    return (0);
}

//
// Created by almayor on 26.03.2020.
//

