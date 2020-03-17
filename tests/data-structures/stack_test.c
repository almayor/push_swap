/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:10:40 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:49:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*push_pull_stack_test(void)
{
	t_stack *s;
	int		rc;
	int		num;

	rc = new_stack(&s);
	ASSERT("STACK: Couldn't create new stack\n", rc == 0);

	rc = push_stack(s, 1);
	ASSERT("STACK: Couldn't push first number\n", rc == 0);
	rc = push_stack(s, -1);
	ASSERT("STACK: Couldn't push second number\n", rc == 0);
	rc = push_stack(s, 0);
	ASSERT("STACK: Couldn't push third number\n", rc == 0);
	rc = push_stack(s, -2147483648);
	ASSERT("STACK: Couldn't push fourth number\n", rc == 0);
	rc = push_stack(s, 2147483647);
	ASSERT("STACK: Couldn't push fifth number\n", rc == 0);

	rc = pull_stack(s, &num);
	ASSERT("STACK: Couldn't pull first number\n", rc == 0);
	ASSERT("STACK: First pushed number is wrong\n", num == 2147483647);
	rc = pull_stack(s, &num);
	ASSERT("STACK: Couldn't pull second number\n", rc == 0);
	ASSERT("STACK: Second pushed number is wrong\n", num == -2147483648);
	rc = pull_stack(s, &num);
	ASSERT("STACK: Couldn't pull third number\n", rc == 0);
	ASSERT("STACK: Third pushed number is wrong\n", num == 0);
	rc = pull_stack(s, &num);
	ASSERT("STACK: Couldn't pull fourth number\n", rc == 0);
	ASSERT("STACK: Fourth pushed number is wrong\n", num == -1);
	rc = pull_stack(s, &num);
	ASSERT("STACK: Couldn't pull fifth number\n", rc == 0);
	ASSERT("STACK: Fifth pushed number is wrong\n", num == 1);

	rc = pull_stack(s, &num);
	ASSERT("STACK: Pull wth no elements yielded wrong return code\n", rc == -1);

	free_stack(s);
	return (0);
}

static char	*append_stack_test(void)
{
	t_stack *s;
	int		rc;
	int		num;

	rc = new_stack(&s);

	rc = append_stack(s, 1);
	ASSERT("STACK: Couldn't append first number\n", rc == 0);
	rc = append_stack(s, 2);
	ASSERT("STACK: Couldn't append second number\n", rc == 0);
	rc = append_stack(s, 3);
	ASSERT("STACK: Couldn't append third number\n", rc == 0);
	rc = append_stack(s, 4);
	ASSERT("STACK: Couldn't append fourth number\n", rc == 0);
	rc = append_stack(s, 5);
	ASSERT("STACK: Couldn't append fifth number\n", rc == 0);

	pull_stack(s, &num);
	ASSERT("STACK: First appended number is wrong\n", num == 1);
	pull_stack(s, &num);
	ASSERT("STACK: Second appended number is wrong\n", num == 2);
	pull_stack(s, &num);
	ASSERT("STACK: Third appended number is wrong\n", num == 3);
	pull_stack(s, &num);
	ASSERT("STACK: Fourth appended number is wrong\n", num == 4);
	pull_stack(s, &num);
	ASSERT("STACK: Fifth appended number is wrong\n", num == 5);

	free_stack(s);
	return (0);
}

static char	*rotate_reverse_rotate_stack_test(void)
{
	t_stack	*s;
	int		rc;
	int		num;

	new_stack(&s);

	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 3);
	append_stack(s, 4);
	append_stack(s, 5);

	rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Single rotate failed\n", num == 2);

	rotate_stack(s);
	rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Double rotate failed\n", num == 5);

	reverse_rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Single reverse rotate failed\n", num == 4);

	reverse_rotate_stack(s);
	reverse_rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Double reverse rotate failed\n", num == 1);

	rotate_stack(s);
	reverse_rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Undo reverse failed\n", num == 3);

	append_stack(s, 0);
	rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Rotate single element failed\n", num == 0);

	append_stack(s, 0);
	reverse_rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Reverse rotate single element failed\n", num == 0);

	num = 5555;
	rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Rotate with no elements failed\n", num == 5555);

	num = 1111;
	reverse_rotate_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Reverse rotate without elements failed\n", num == 1111);

	free_stack(s);

	new_stack(&s);
	rc = rotate_stack(s);
	ASSERT("STACK: Rotate with no elements yielded wrong return code\n", rc == -1);
	append_stack(s, 1);
	rc = rotate_stack(s);
	ASSERT("STACK: Rotate with one element yielded wrong return code\n", rc == -1);
	free_stack(s);

	new_stack(&s);
	rc = reverse_rotate_stack(s);
	ASSERT("STACK: Reverse rotate with no elements yielded wrong return code\n", rc == -1);
	append_stack(s, 1);
	rc = reverse_rotate_stack(s);
	ASSERT("STACK: Reverse rotate with one element yielded wrong return code\n", rc == -1);
	free_stack(s);

	return (0);
}

static char		*swap_stack_test(void)
{
	t_stack *s;
	int		num;
	int		rc;

	new_stack(&s);

	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 3);
	append_stack(s, 4);
	append_stack(s, 5);

	swap_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Swap with 5 elements failed\n", num == 2);

	swap_stack(s);
	swap_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Double swap with 4 elements didn't result in unchanged state\n", num == 1);

	swap_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Swap with 3 elements failed\n", num == 4);

	swap_stack(s);
	pull_stack(s, &num);
	ASSERT("STACK: Swap with 2 elements failed\n", num == 5);

	rc = swap_stack(s);
	ASSERT("STACK: Swap with 1 element yielded wrong return code\n", rc == -1);
	pull_stack(s, &num);
	ASSERT("STACK: Swap with 1 element failed\n", num == 3);

	rc = swap_stack(s);
	ASSERT("STACK: Swap with no elements yielded wrong return code\n", rc == -1);
	num = 5555;
	pull_stack(s, &num);
	ASSERT("STACK: Swap with no elements failed\n", num == 5555);

	free_stack(s);

	new_stack(&s);
	rc = swap_stack(s);
	ASSERT("STACK: Swap with no elements yielded wrong return code\n", rc == -1);
	append_stack(s, 1);
	rc = swap_stack(s);
	ASSERT("STACK: Swap with one element yielded wrong return code\n", rc == -1);
	free_stack(s);

	return (0);
}

static char		*copy_stack_test(void)
{
	t_stack	*s1;
	t_stack *s2;
	int		rc;
	int		num;

	new_stack(&s1);
	append_stack(s1, 1);
	append_stack(s1, 2);
	append_stack(s1, 3);
	append_stack(s1, 4);
	append_stack(s1, 5);

	rc = copy_stack(s1, &s2);
	ASSERT("STACK: Copy stack failed\n", rc == 0);

	free_stack(s1);

	pull_stack(s2, &num);
	ASSERT("STACK: First copied number is wrong\n", num == 1);
	pull_stack(s2, &num);
	ASSERT("STACK: Second copied number is wrong\n", num == 2);
	pull_stack(s2, &num);
	ASSERT("STACK: Third copied number is wrong\n", num == 3);
	pull_stack(s2, &num);
	ASSERT("STACK: Fourth copied number is wrong\n", num == 4);
	pull_stack(s2, &num);
	ASSERT("STACK: Fifth copied number is wrong\n", num == 5);

	free_stack(s2);
	return (0);
}

static char		*is_sorted_stack_test(void)
{
	t_stack	*s;
	int		rc;

	new_stack(&s);
	rc = is_sorted_stack(s);
	ASSERT("STACK: Sorted stack with no elements declared as unsorted\n", rc == 1);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 3);
	append_stack(s, 4);
	append_stack(s, 5);
	rc = is_sorted_stack(s);
	ASSERT("STACK: Sorted stack with 5 elements declared as unsorted\n", rc == 1);
	free_stack(s);

	new_stack(&s);
	append_stack(s, -1);
	append_stack(s, 1);
	rc = is_sorted_stack(s);
	ASSERT("STACK: Sorted stack with 2 elements declared as unsorted\n", rc == 1);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 5);
	append_stack(s, 0);
	append_stack(s, 3);
	rc = is_sorted_stack(s);
	ASSERT("STACK: Unsorted stack with 5 elements declared as sorted\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, -1);
	rc = is_sorted_stack(s);
	ASSERT("STACK: Unsorted stack with 2 elements declared as sorted\n", rc == 0);
	free_stack(s);

	return (0);
}

static char		*is_empty_stack_test(void)
{
	t_stack	*s;
	int		rc;

	new_stack(&s);
	rc = is_empty_stack(s);
	ASSERT("STACK: Empty stack declared as non-empty\n", rc == 1);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	rc = is_empty_stack(s);
	ASSERT("STACK: Non-empty stack with one element declared as empty\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 5);
	append_stack(s, 0);
	append_stack(s, 3);
	rc = is_empty_stack(s);
	ASSERT("STACK: Non-empty stack with five elements declared as empty\n", rc == 0);
	free_stack(s);

	return (0);
}

static char		*has_duplicates_stack_test(void)
{
	t_stack	*s;
	int		rc;

	new_stack(&s);
	rc = has_duplicates_stack(s);
	ASSERT("STACK: Empty stack declared as having duplicates\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	rc = has_duplicates_stack(s);
	ASSERT("STACK: Stack with one element declared as having duplicates\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	rc = has_duplicates_stack(s);
	ASSERT("STACK: Stack with two different element declared as having duplicates\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 1);
	rc = has_duplicates_stack(s);
	ASSERT("STACK: Stack with two identical element declared as not having duplicates\n", rc == 1);
	free_stack(s);

	return (0);
}

static char		*len_stack_test(void)
{
	t_stack	*s;
	int		rc;

	new_stack(&s);
	rc = len_stack(s);
	ASSERT("STACK: Wrong stack length with empty stack\n", rc == 0);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	rc = len_stack(s);
	ASSERT("STACK: Wrong stack length with 1 in stack\n", rc == 1);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	rc = len_stack(s);
	ASSERT("STACK: Wrong stack length with 1->2 in stack\n", rc == 2);
	free_stack(s);

	new_stack(&s);
	append_stack(s, 1);
	append_stack(s, 2);
	append_stack(s, 3);
	rc = len_stack(s);
	ASSERT("STACK: Wrong stack length with 1->2->3 in stack\n", rc == 3);
	free_stack(s);

	return (0);
}

char			*stack_test(void)
{
	RUN_TEST(push_pull_stack_test);
	RUN_TEST(append_stack_test);
	RUN_TEST(rotate_reverse_rotate_stack_test);
	RUN_TEST(swap_stack_test);
	RUN_TEST(copy_stack_test);
	RUN_TEST(is_sorted_stack_test);
	RUN_TEST(is_empty_stack_test);
	RUN_TEST(has_duplicates_stack_test);
	RUN_TEST(len_stack_test);
	return (0);
}
