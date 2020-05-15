#include "minunit.h"

void stack_suite(void);

int	main() {
	MU_RUN_SUITE(stack_suite);
	return MU_EXIT_CODE;
}
