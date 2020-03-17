/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:58:05 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 17:05:32 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*pop_push_heap_test(void)
{
	t_heap	*h;
	char	*c;
	int		rc;

	rc = new_heap(&h);
	ASSERT("HEAP: Couldn't create new heap\n", rc == 0);

    rc = push_heap(h, 3, "Clear drains");
    ASSERT("HEAP: Couldn't push first element \n", rc == 0);
    rc = push_heap(h, 4, "Feed cat");
    ASSERT("HEAP: Couldn't push second element \n", rc == 0);
    rc = push_heap(h, 5, "Make tea");
    ASSERT("HEAP: Couldn't push third element \n", rc == 0);
    rc = push_heap(h, 1, "Solve RC tasks");
    ASSERT("HEAP: Couldn't push fourth element \n", rc == 0);
    rc = push_heap(h, 2, "Tax return");
    ASSERT("HEAP: Couldn't push fifth element \n", rc == 0);
    
    rc = pop_heap(h, (void **)&c);
    ASSERT("HEAP: Couldn't pop first-priority element\n", rc == 0);
    ASSERT("HEAP: First element isn't Solve RC tasks\n", ft_strequ(c, "Solve RC tasks"));
    rc = pop_heap(h, (void **)&c);
    ASSERT("HEAP: Couldn't pop second-priority element\n", rc == 0);
    ASSERT("HEAP: Second element isn't Tax return\n", ft_strequ(c, "Tax return"));
    rc = pop_heap(h, (void **)&c);
    ASSERT("HEAP: Couldn't pop third-priority element\n", rc == 0);
    ASSERT("HEAP: Third element isn't Clear drains\n", ft_strequ(c, "Clear drains"));
    rc = pop_heap(h, (void **)&c);
    ASSERT("HEAP: Couldn't pop fourth-priority element\n", rc == 0);
    ASSERT("HEAP: Fourth element isn't Feed cat\n", ft_strequ(c, "Feed cat"));
    rc = pop_heap(h, (void **)&c);
    ASSERT("HEAP: Couldn't pop fifth-priority element\n", rc == 0);
    ASSERT("HEAP: Fifth element isn't Make tea\n", ft_strequ(c, "Make tea"));

    free_heap(h);
    return (0);
}

char		*heap_test(void)
{
	RUN_TEST(pop_push_heap_test);
	return (0);
}
