/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:15:10 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 10:44:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int tests_run = 0;

static char	*all_tests(void)
{
	RUN_TEST(heap_test);
	ft_printf("HEAP:\t\tOK\n");
	RUN_TEST(queue_test);
	ft_printf("QUEUE:\t\tOK\n");
	RUN_TEST(stack_test);
	ft_printf("STACK:\t\tOK\n");
	RUN_TEST(state_test);
	ft_printf("STATE:\t\tOK\n");
	RUN_TEST(operations_test);
	ft_printf("OPERATIONS:\tOK\n");
	RUN_TEST(is_numeric_str_test);
	ft_printf("IS_NUMERIC_STR:\tOK\n");
	RUN_TEST(ft_atoi2_test);
	ft_printf("FT_ATOI2:\tOK\n");
	RUN_TEST(A_search_test);
	ft_printf("A_SEARCH:\tOK\n");
	return (0);
}
int			main(void)
{
	char	*result = all_tests();

	if (result != 0)
	{
        ft_printf("%s\n", result);
        ft_printf("\n{red}TESTS FAILED{eoc}\n");
	}
    else
    {
        ft_printf("\n{green}ALL TESTS PASSED{eoc}\n");
    }
    ft_printf("Tests run: %d\n", tests_run);

    return result != 0;
}
