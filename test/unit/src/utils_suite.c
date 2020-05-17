#include "minunit.h"
#include "push_swap.h"
#include <errno.h>
#include <limits.h>

MU_TEST(test_atoi) {
	int		val;

	mu_check(ps_atoi("153", &val) == 0);
	mu_check(val == 153);
	mu_check(ps_atoi("+6453", &val) == 0);
	mu_check(val == 6453);
	mu_check(ps_atoi("-6", &val) == 0);
	mu_check(val == -6);

	mu_check(ps_atoi("0", &val) == 0);
	mu_check(val == 0);
	mu_check(ps_atoi("+0", &val) == 0);
	mu_check(val == 0);
	mu_check(ps_atoi("-0", &val) == 0);
	mu_check(val == 0);

	mu_check(ps_atoi("+2147483647", &val) == 0);
	mu_check(val == 2147483647);
	mu_check(ps_atoi("-2147483648", &val) == 0);
	mu_check(val == -2147483648);

	mu_check(ps_atoi("2147483648", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;
	mu_check(ps_atoi("-2147483649", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;

	mu_check(ps_atoi("9223372036854775808", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;
	mu_check(ps_atoi("-9223372036854775808", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;

	mu_check(ps_atoi("99999999999999999999999999999999999999999", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;
	mu_check(ps_atoi("-99999999999999999999999999999999999999999", &val) != 0);
	mu_check(errno == EOVERFLOW);
	errno = 0;
}

MU_TEST(test_isnumeric_str) {
	mu_check(ps_isnumeric_str("0") == 1);
	mu_check(ps_isnumeric_str("-1") == 1);
	mu_check(ps_isnumeric_str("+1") == 1);
	mu_check(ps_isnumeric_str("-127373") == 1);
	mu_check(ps_isnumeric_str("+162736") == 1);
	mu_check(ps_isnumeric_str("b2123") == 0);
	mu_check(ps_isnumeric_str("-891%") == 0);
	mu_check(ps_isnumeric_str("hello") == 0);
	mu_check(ps_isnumeric_str("1777$777") == 0);
}

MU_TEST(test_index_stack) {
	t_stack	st;

	new_stack(&st);
	ps_index_stack(&st);
	mu_check(st.size == 0);
	mu_check(st.start == NULL);
	mu_check(st.end == NULL);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 1);
	append_stack(&st, 2);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 1);
	mu_check(pull_stack(&st) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 1);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 2);
	mu_check(pull_stack(&st) == 1);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 2);
	append_stack(&st, 1);
	append_stack(&st, 3);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 2);
	mu_check(pull_stack(&st) == 1);
	mu_check(pull_stack(&st) == 3);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 80);
	append_stack(&st, -101);
	append_stack(&st, -100);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 3);
	mu_check(pull_stack(&st) == 1);
	mu_check(pull_stack(&st) == 2);
	free_stack(&st);

	new_stack(&st);
	append_stack(&st, 18);
	append_stack(&st, -2345);
	append_stack(&st, 3114);
	append_stack(&st, 14);
	ps_index_stack(&st);
	mu_check(pull_stack(&st) == 3);
	mu_check(pull_stack(&st) == 1);
	mu_check(pull_stack(&st) == 4);
	mu_check(pull_stack(&st) == 2);
	free_stack(&st);
}

MU_TEST(test_tab2stack) {
	t_stack st;

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ NULL }, &st) == 0);
	mu_check(st.size == 0);
	mu_check(st.start == NULL);
	mu_check(st.end == NULL);
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "192", NULL }, &st) == 0);
	mu_check(st.size == 1);
	mu_check(pull_stack(&st) == 192);
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "-0", "-46575", NULL }, &st) == 0);
	mu_check(st.size == 2);
	mu_check(pull_stack(&st) == 0);
	mu_check(pull_stack(&st) == -46575);
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "1000005", "14", "-2", NULL }, &st) == 0);
	mu_check(st.size == 3);
	mu_check(pull_stack(&st) == 1000005);
	mu_check(pull_stack(&st) == 14);
	mu_check(pull_stack(&st) == -2);
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "475", "14a5", "-2", NULL }, &st) != 0);
	mu_check(errno == EINVAL);
	errno = 0;
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "475", "-444", "475", NULL }, &st) != 0);
	mu_check(errno == EINVAL);
	errno = 0;
	free_stack(&st);

	new_stack(&st);
	mu_check(ps_tab2stack((char *[]){ "475", "-4444736475654839283", NULL }, &st) != 0);
	mu_check(errno == EINVAL);
	errno = 0;
	free_stack(&st);
}

int utils_suite(void) {
	ft_printf("Running %s:\n", __FUNCTION__);
	MU_RUN_TEST(test_atoi);
	MU_RUN_TEST(test_isnumeric_str);
	MU_RUN_TEST(test_index_stack);
	MU_RUN_TEST(test_tab2stack);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
