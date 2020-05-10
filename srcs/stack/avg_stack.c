//
// Created by almayor on 26.03.2020.
//

#include "stack.h"

int     avg_stack(t_stack *stack, size_t length, int *avg)
{
    t_link  *link;
    size_t  i;

    if (length > stack->size || stack->size == 0 || length == 0)
        return (1);
    *avg = 0;
    i = 0;
    link = stack->start;
    while (i < length)
    {
        *avg += link->value;
        link = link->next;
        i++;
    }
    *avg /= length;
    return (0);
}

//
// Created by almayor on 26.03.2020.
//

//
// Created by almayor on 26.03.2020.
//

