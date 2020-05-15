#include "minunit.h"
#include "push_swap.h"
#include <limits.h>

MU_TEST(test_perform_sa) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "sa");
	mu_check(pull_stack(&sa) == 2);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_sb) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "sb");
	mu_check(pull_stack(&sb) == -2);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_ss) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "ss");
	mu_check(pull_stack(&sa) == 2);
	mu_check(pull_stack(&sb) == -2);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_pa) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "pa");
	mu_check(pull_stack(&sa) == -1);
	free_stack(&sa);
	free_stack(&sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "pa");
	mu_check(pull_stack(&sa) == -1);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_pb) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "pb");
	mu_check(pull_stack(&sb) == 1);
	free_stack(&sa);
	free_stack(&sb);

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	perform_operation(&sa, &sb, "pb");
	mu_check(pull_stack(&sb) == 1);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_ra) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "ra");
	mu_check(pull_stack(&sa) == 2);
	mu_check(pull_stack(&sb) == -1);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_rb) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "rb");
	mu_check(pull_stack(&sa) == 1);
	mu_check(pull_stack(&sb) == -2);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_rr) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "rr");
	mu_check(pull_stack(&sa) == 2);
	mu_check(pull_stack(&sb) == -2);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_rra) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "rra");
	mu_check(pull_stack(&sa) == 3);
	mu_check(pull_stack(&sb) == -1);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_rrb) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "rrb");
	mu_check(pull_stack(&sa) == 1);
	mu_check(pull_stack(&sb) == -3);
	free_stack(&sa);
	free_stack(&sb);
}

MU_TEST(test_perform_rrr) {
	t_stack	sa;
	t_stack sb;

	new_stack(&sa);
	new_stack(&sb);
	append_stack(&sa, 1);
	append_stack(&sa, 2);
	append_stack(&sa, 3);
	append_stack(&sb, -1);
	append_stack(&sb, -2);
	append_stack(&sb, -3);
	perform_operation(&sa, &sb, "rrr");
	mu_check(pull_stack(&sa) == 3);
	mu_check(pull_stack(&sb) == -3);
	free_stack(&sa);
	free_stack(&sb);
}

int operations_suite(void) {
	ft_printf("Running %s:\n", __FUNCTION__);
	MU_RUN_TEST(test_perform_sa);
	MU_RUN_TEST(test_perform_sb);
	MU_RUN_TEST(test_perform_ss);
	MU_RUN_TEST(test_perform_pa);
	MU_RUN_TEST(test_perform_pb);
	MU_RUN_TEST(test_perform_ra);
	MU_RUN_TEST(test_perform_rb);
	MU_RUN_TEST(test_perform_rr);
	MU_RUN_TEST(test_perform_rra);
	MU_RUN_TEST(test_perform_rrb);
	MU_RUN_TEST(test_perform_rrr);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
