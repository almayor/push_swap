#include "minunit.h"
#include "stack.h"
#include <limits.h>

MU_TEST(test_new) {
	t_stack st;

	new_stack(&st);
	mu_check(st.start == 0);
	mu_check(st.end == 0);
	mu_check(st.size == 0);
}

MU_TEST(test_push) {
	t_stack st;
	t_link	*li;

	new_stack(&st);
	push_stack(&st, INT_MIN);
	push_stack(&st, 0);
	push_stack(&st, -3);
	push_stack(&st, 1);
	push_stack(&st, INT_MAX);

	li = st.start;
	mu_check(li->value == INT_MAX);
	li = li->next;
	mu_check(li->value == 1);
	li = li->next;
	mu_check(li->value == -3);
	li = li->next;
	mu_check(li->value == 0);
	li = li->next;
	mu_check(li->value == INT_MIN);
	li = li->next;
	mu_check(li == NULL);
}

MU_TEST(test_pull) {
	t_stack st;
	int		val;

	new_stack(&st);
	push_stack(&st, INT_MIN);
	push_stack(&st, 0);
	push_stack(&st, -3);
	push_stack(&st, 1);
	push_stack(&st, INT_MAX);

	val = pull_stack(&st);
	mu_check(val == INT_MAX);
	val = pull_stack(&st);
	mu_check(val == 1);
	val = pull_stack(&st);
	mu_check(val == -3);
	val = pull_stack(&st);
	mu_check(val == 0);
	val = pull_stack(&st);
	mu_check(val == INT_MIN);
	val = pull_stack(&st);
	mu_check(val == 0);
}

MU_TEST(test_append) {
	t_stack st;
	int		val;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 5555);
	append_stack(&st, -10);
	append_stack(&st, 24);
	append_stack(&st, INT_MIN);

	val = pull_stack(&st);
	mu_check(val == INT_MAX);
	val = pull_stack(&st);
	mu_check(val == 5555);
	val = pull_stack(&st);
	mu_check(val == -10);
	val = pull_stack(&st);
	mu_check(val == 24);
	val = pull_stack(&st);
	mu_check(val == INT_MIN);
}

MU_TEST(test_rotate) {
	t_stack st;
	int		val;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 5555);
	append_stack(&st, -10);
	append_stack(&st, 24);
	append_stack(&st, INT_MIN);

	rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 5555);
	rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 24);
	rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MAX);
	rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MIN);
	rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == -10);
}

MU_TEST(test_reverse_rotate) {
	t_stack st;
	int		val;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 5555);
	append_stack(&st, -10);
	append_stack(&st, 24);
	append_stack(&st, INT_MIN);

	reverse_rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MIN);
	reverse_rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 24);
	reverse_rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == -10);
	reverse_rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 5555);
	reverse_rotate_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MAX);
}

MU_TEST(test_swap) {
	t_stack st;
	int		val;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 5555);
	append_stack(&st, -10);
	append_stack(&st, 24);
	append_stack(&st, INT_MIN);

	swap_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 5555);
	swap_stack(&st);
	val = pull_stack(&st);
	mu_check(val == -10);
	swap_stack(&st);
	val = pull_stack(&st);
	mu_check(val == 24);
	swap_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MIN);
	swap_stack(&st);
	val = pull_stack(&st);
	mu_check(val == INT_MAX);
}

MU_TEST(test_issorted) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 3);
	mu_check(issorted_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, 3);
	mu_check(issorted_stack(&st) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 3);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, 0);
	append_stack(&st, -1);
	mu_check(issorted_stack(&st) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	mu_check(issorted_stack(&st) == 1);
	free_stack(&st);
}

MU_TEST(test_isset) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, 1);
	mu_check(isset_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, -1);
	mu_check(isset_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 1);
	mu_check(isset_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 1);
	mu_check(isset_stack(&st) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 1);
	mu_check(isset_stack(&st) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, 3);
	mu_check(isset_stack(&st) == 0);
	free_stack(&st);
}

MU_TEST(test_get) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 3);
	mu_check(get_stack(&st, 0) == -1);
	mu_check(get_stack(&st, 1) == 0);
	mu_check(get_stack(&st, 2) == 1);
	mu_check(get_stack(&st, 3) == 2);
	mu_check(get_stack(&st, 4) == 3);
	free_stack(&st);
}

MU_TEST(test_min) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 0);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, INT_MIN);
	mu_check(min_stack(&st) == INT_MIN);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 0);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, INT_MIN);
	mu_check(min_stack(&st) == INT_MIN);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 0);
	append_stack(&st, 1);
	mu_check(min_stack(&st) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 1);
	mu_check(min_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	mu_check(min_stack(&st) == 1);
	free_stack(&st);
}

MU_TEST(test_max) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, INT_MAX);
	append_stack(&st, 0);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, INT_MIN);
	mu_check(max_stack(&st) == INT_MAX);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 0);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, INT_MIN);
	mu_check(max_stack(&st) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 0);
	append_stack(&st, 1);
	mu_check(max_stack(&st) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 1);
	mu_check(max_stack(&st) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	mu_check(max_stack(&st) == 1);
	free_stack(&st);
}

MU_TEST(test_avg) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 3);
	mu_check(avg_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 1);
	append_stack(&st, 3);
	mu_check(avg_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	mu_check(avg_stack(&st) == 1);
	free_stack(&st);
}

MU_TEST(test_search) {
	t_stack st;

	new_stack(&st);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 1);
	append_stack(&st, 2);
	append_stack(&st, 3);
	mu_check(search_stack(&st, 1) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 0);
	append_stack(&st, -1);
	append_stack(&st, 3);
	mu_check(search_stack(&st, 2) == -1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 0);
	append_stack(&st, -1);
	append_stack(&st, 3);
	mu_check(search_stack(&st, 1) == 0);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, -1);
	append_stack(&st, 0);
	append_stack(&st, 3);
	mu_check(search_stack(&st, 3) == 3);
	free_stack(&st);
}

int stack_suite(void) {
	ft_printf("Running %s:\n", __FUNCTION__);
	MU_RUN_TEST(test_new);
	MU_RUN_TEST(test_push);
	MU_RUN_TEST(test_pull);
	MU_RUN_TEST(test_append);
	MU_RUN_TEST(test_rotate);
	MU_RUN_TEST(test_reverse_rotate);
	MU_RUN_TEST(test_swap);
	MU_RUN_TEST(test_issorted);
	MU_RUN_TEST(test_isset);
	MU_RUN_TEST(test_get);
	MU_RUN_TEST(test_min);
	MU_RUN_TEST(test_max);
	MU_RUN_TEST(test_avg);
	MU_RUN_TEST(test_search);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
