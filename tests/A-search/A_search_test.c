/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_search_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 09:37:14 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 20:02:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*A_search_test(void)
{
	t_stack	*stack;
	t_queue	*trace;
	int		rc;
	int		len;
	char	*oper;

	new_stack(&stack);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with empty stack failed\n", rc == 0);
	oper = "hiya there!";
	dequeue_queue(trace, &oper);
	ASSERT("A_SEARCH: search with empty stack gave non-empty trace\n", ft_strequ(oper, "hiya there!"));
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 1);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 1 in stack failed\n", rc == 0);
	oper = "hiya there!";
	dequeue_queue(trace, &oper);
	ASSERT("A_SEARCH: search with 1 in stack gave non-empty trace\n", ft_strequ(oper, "hiya there!"));
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 1);
	append_stack(stack, 2);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 1->2 in stack failed\n", rc == 0);
	oper = "hiya there!";
	dequeue_queue(trace, &oper);
	ASSERT("A_SEARCH: search with 1->2 in stack gave non-empty trace\n", ft_strequ(oper, "hiya there!"));
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 2);
	append_stack(stack, 1);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 2->1 in stack failed\n", rc == 0);
	dequeue_queue(trace, &oper);
	ASSERT("A_SEARCH: search with 2->1 in stack gave wrong trace\n", ft_strequ(oper, "ra"));
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 2);
	append_stack(stack, 1);
	append_stack(stack, 3);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 2->1->3 in stack failed\n", rc == 0);
	dequeue_queue(trace, &oper);
	ASSERT("A_SEARCH: search with 2->1->3 in stack gave wrong trace\n", ft_strequ(oper, "sa"));
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 2);
	append_stack(stack, 1);
	append_stack(stack, 0);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 2->1->0 in stack failed\n", rc == 0);
	len = len_queue(trace);
	ASSERT("A_SEARCH: search with 2->1->0 in stack gave trace that is too long\n", len == 2);
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 1);
	append_stack(stack, 3);
	append_stack(stack, 4);
	append_stack(stack, 2);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 1->3->4->2 in stack failed\n", rc == 0);
	len = len_queue(trace);
	ASSERT("A_SEARCH: search with 1->3->4->2 in stack gave trace that is too long\n", len == 2);
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 3);
	append_stack(stack, 1);
	append_stack(stack, 4);
	append_stack(stack, 2);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 3->1->4->2 in stack failed\n", rc == 0);
	len = len_queue(trace);
	ASSERT("A_SEARCH: search with 3->1->4->2 in stack gave trace that is too long\n", len == 3);
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 1);
	append_stack(stack, 4);
	append_stack(stack, 3);
	append_stack(stack, 2);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 1->4->3->2 in stack failed\n", rc == 0);
	len = len_queue(trace);
	ASSERT("A_SEARCH: search with 1->4->3->2 in stack gave trace that is too long\n", len == 4);
	free_stack(stack);
	free_queue(trace);

	new_stack(&stack);
	append_stack(stack, 1);
	append_stack(stack, 5);
	append_stack(stack, 2);
	append_stack(stack, 4);
	append_stack(stack, 3);
	rc = A_search(stack, &trace);
	ASSERT("A_SEARCH: search with 1->5->2->4->3 in stack failed\n", rc == 0);
	len = len_queue(trace);
	ASSERT("A_SEARCH: search with 1->5->2->4->3 in stack gave trace that is too long\n", len == 6);
	free_stack(stack);
	free_queue(trace);

	return (0);
}
