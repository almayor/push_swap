/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:17:10 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:41:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*ra_rb_rr_operations_test(void)
{
	t_stack	*sa;
	t_stack	*sb;
	int		rc;
	int		num;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "ra");
	ASSERT("OPERATIONS: ra with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: ra failed\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "rb");
	ASSERT("OPERATIONS: rb with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: rb failed\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	append_stack(sb, -1);
	append_stack(sb, -2);
	append_stack(sb, -3);
	rc = perform_operation(sa, sb, "rr");
	ASSERT("OPERATIONS: rr with 3 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: rr failed\n", num == 2);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: rr failed\n", num == -2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "ra");
	ASSERT("OPERATIONS: ra with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "rb");
	ASSERT("OPERATIONS: rb with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	return (0);
}

static char	*rra_rrb_rrr_operations_test(void)
{
	t_stack	*sa;
	t_stack	*sb;
	int		rc;
	int		num;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "rra");
	ASSERT("OPERATIONS: rra with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: rra failed\n", num == 3);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "rrb");
	ASSERT("OPERATIONS: rrb with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: rrb failed\n", num == 3);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	append_stack(sb, -1);
	append_stack(sb, -2);
	append_stack(sb, -3);
	rc = perform_operation(sa, sb, "rrr");
	ASSERT("OPERATIONS: rrr with 3 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: rrr failed\n", num == 3);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: rrr failed\n", num == -3);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "rra");
	ASSERT("OPERATIONS: rra with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "rrb");
	ASSERT("OPERATIONS: rrb with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "rrr");
	ASSERT("OPERATIONS: rrr with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "rrr");
	ASSERT("OPERATIONS: rrr with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	return (0);
}

static char	*sa_sb_ss_operations_test(void)
{
	t_stack	*sa;
	t_stack	*sb;
	int		rc;
	int		num;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "sa");
	ASSERT("OPERATIONS: sa with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: sa failed\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "sb");
	ASSERT("OPERATIONS: sb with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: sb failed\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	append_stack(sb, -1);
	append_stack(sb, -2);
	append_stack(sb, -3);
	rc = perform_operation(sa, sb, "ss");
	ASSERT("OPERATIONS: ss with 3 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: ss failed\n", num == 2);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: ss failed\n", num == -2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "sa");
	ASSERT("OPERATIONS: sa with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "sb");
	ASSERT("OPERATIONS: sb with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "ss");
	ASSERT("OPERATIONS: ss with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "ss");
	ASSERT("OPERATIONS: ss with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	return (0);
}

static char	*pa_pb_operations_test(void)
{
	t_stack	*sa;
	t_stack	*sb;
	int		rc;
	int		num;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "pa");
	ASSERT("OPERATIONS: pa with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: pa with 0 in stackA, 3 in stackB failed at stackA\n", num == 1);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: pa with 0 in stackA, 3 in stackB failed at stackB\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "pb");
	ASSERT("OPERATIONS: pb with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: pb with 3 in stackA, 0 in stackB failed at stackA\n", num == 2);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: pb with 3 in stackA, 0 in stackB failed at stackB\n", num == 1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	append_stack(sa, 0);
	rc = perform_operation(sa, sb, "pa");
	ASSERT("OPERATIONS: pa with 1 in stackA, 3 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: pa with 1 in stackA, 3 in stackB failed at stackA\n", num == 1);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: pa with 1 in stackA, 3 in stackB failed at stackB\n", num == 2);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	append_stack(sb, 0);
	rc = perform_operation(sa, sb, "pb");
	ASSERT("OPERATIONS: pb with 3 in stackA, 1 in stackB yielded wrong return code\n", rc == 0);
	pull_stack(sa, &num);
	ASSERT("OPERATIONS: pb with 3 in stackA, 1 in stackB failed at stackA\n", num == 2);
	pull_stack(sb, &num);
	ASSERT("OPERATIONS: pb with 3 in stackA, 1 in stackB failed at stackB\n", num == 1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sb, 1);
	append_stack(sb, 2);
	append_stack(sb, 3);
	rc = perform_operation(sa, sb, "pb");
	ASSERT("OPERATIONS: pa with 0 in stackA, 3 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(sa, 1);
	append_stack(sa, 2);
	append_stack(sa, 3);
	rc = perform_operation(sa, sb, "pa");
	ASSERT("OPERATIONS: pb with 3 in stackA, 0 in stackB yielded wrong return code\n", rc == -1);
	free_stack(sa);
	free_stack(sb);

	return (0);
}

char		*operations_test(void)
{
	RUN_TEST(ra_rb_rr_operations_test);
	RUN_TEST(rra_rrb_rrr_operations_test);
	RUN_TEST(sa_sb_ss_operations_test);
	RUN_TEST(pa_pb_operations_test);
	return (0);
}
