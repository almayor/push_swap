/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 08:07:27 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:39:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*heuristic_state_test(void)
{
	t_state	*state;
	t_stack	*stackA;
	int		h;

	new_stack(&stackA);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with none in stackA, none in stackB\n", h == 0);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with 1->2 in stackA, none in stackB\n", h == 0);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 2);
	append_stack(stackA, 1);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with 2->1 in stackA, none in stackB\n", h == 1);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with 1->2->3 in stackA, none in stackB\n", h == 0);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 3);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with 3->1->2 in stackA, none in stackB\n", h == 1);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 3);
	append_stack(stackA, 2);
	append_stack(stackA, 1);
	new_state(&state, stackA);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with 3->2->1 in stackA, none in stackB\n", h == 2);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	new_state(&state, stackA);
	append_stack(state->stackB, 3);
	append_stack(state->stackB, 2);
	append_stack(state->stackB, 1);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with none in stackA, 3->2->1 in stackB\n", h == 3);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	new_state(&state, stackA);
	append_stack(state->stackA, -3);
	append_stack(state->stackA, -2);
	append_stack(state->stackA, -1);
	append_stack(state->stackB, 3);
	append_stack(state->stackB, 2);
	append_stack(state->stackB, 1);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with -3->-2->-1 in stackA, 3->2->1 in stackB\n", h == 3);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	new_state(&state, stackA);
	append_stack(state->stackA, -3);
	append_stack(state->stackA, -1);
	append_stack(state->stackA, -2);
	append_stack(state->stackB, 3);
	append_stack(state->stackB, 2);
	append_stack(state->stackB, 1);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with -3->-1->-2 in stackA, 3->2->1 in stackB\n", h == 4);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	new_state(&state, stackA);
	append_stack(state->stackA, -3);
	append_stack(state->stackA, -1);
	append_stack(state->stackA, -2);
	append_stack(state->stackB, 3);
	append_stack(state->stackB, 1);
	append_stack(state->stackB, 2);
	h = heuristic_state(state);
	ASSERT("STATE: wrong heuristic with -3->-1->-2 in stackA, 3->1->2 in stackB\n", h == 5);
	free_stack(stackA);
	free_state(state);

	return (0);
}

static char	*new_state_test(void)
{
	t_state	*state;
	t_stack	*stackA;
	int		rc;

	new_stack(&stackA);
	rc = new_state(&state, stackA);
	ASSERT("STATE: new_state with empty stack failed\n", rc == 0);
	ASSERT("STATE: new_state with empty stack assigned incorrect g\n", state->g == 0);
	ASSERT("STATE: new_state with empty stack assigned incorrect h\n", state->h == 0);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 3);
	append_stack(stackA, 2);
	rc = new_state(&state, stackA);
	ASSERT("STATE: new_state with 1->3->2 failed\n", rc == 0);
	ASSERT("STATE: new_state with 1->3->2 assigned incorrect g\n", state->g == 0);
	ASSERT("STATE: new_state with 1->3->2 assigned incorrect h\n", state->h == 1);
	free_stack(stackA);
	free_state(state);

	return (0);
}

static char	*is_goal_state_test(void)
{
	t_state	*state;
	t_stack	*stackA;
	int		rc;

	new_stack(&stackA);
	new_state(&state, stackA);
	rc = is_goal_state(state);
	ASSERT("STATE: state with empty stacks declared as non-goal\n", rc == 1);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	new_state(&state, stackA);
	rc = is_goal_state(state);
	ASSERT("STATE: state with 1->2 in stackA, empty in stackB declared as non-goal\n", rc == 1);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 2);
	append_stack(stackA, 1);
	new_state(&state, stackA);
	rc = is_goal_state(state);
	ASSERT("STATE: state with 2->1 in stackA, empty in stackB declared as goal\n", rc == 0);
	free_stack(stackA);
	free_state(state);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state, stackA);
	append_stack(state->stackB, 1);
	rc = is_goal_state(state);
	ASSERT("STATE: state with 1->2->3 in stackA, 1 in stackB declared as goal\n", rc == 0);
	free_stack(stackA);
	free_state(state);

	return (0);
}

static char	*copy_state_test(void)
{
	t_state	*state1;
	t_state	*state2;
	t_stack	*stackA;
	int		rc;
	int		num;
	char	*oper;

	new_stack(&stackA);
	new_state(&state1, stackA);
	rc = copy_state(state1, &state2);
	ASSERT("STATE: copy_state with nothing in stackA, nothing in stackB failed\n", rc == 0);
	free_state(state1);
	free_state(state2);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state1, stackA);
	copy_state(state1, &state2);
	free_state(state1);
	pull_stack(state2->stackA, &num);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, gave incorrect stackA in child\n", num == 1);
	pull_stack(state2->stackA, &num);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, gave incorrect stackA in child\n", num == 2);
	pull_stack(state2->stackA, &num);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, gave incorrect stackA in child\n", num == 3);
	free_state(state2);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state1, stackA);
	enqueue_queue(state1->trace, "sa");
	copy_state(state1, &state2);
	free_state(state1);
	dequeue_queue(state2->trace, &oper);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, sa in trace, gave incorrect trace in child\n", ft_strequ(oper, "sa"));
	free_state(state2);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state1, stackA);
	state1->h = 10;
	copy_state(state1, &state2);
	free_state(state1);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, sa in trace, gave incorrect h in child\n", state2->h == 10);
	free_state(state2);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&state1, stackA);
	state1->g = 8;
	copy_state(state1, &state2);
	free_state(state1);
	ASSERT("STATE: copy_state with 1->2->3 in stackA, nothing in stackB, sa in trace, gave incorrect g in child\n", state2->g == 8);
	free_state(state2);
	free_stack(stackA);

	return (0);
}

static char	*succeed_state_test(void)
{
	t_state	*parent;
	t_state	*child;
	t_stack	*stackA;
	int		rc;
	int		num;
	char	*oper;

	new_stack(&stackA);
	new_state(&parent, stackA);
	rc = succeed_state(parent, &child, "sa");
	ASSERT("STATE: succeed_state with nothing in stackA, nothing in stackB, sa operation failed\n", rc == -1);
	free_state(parent);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&parent, stackA);
	rc = succeed_state(parent, &child, "ra");
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, ra operation failed\n", rc == 0);
	pull_stack(child->stackA, &num);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, ra operation gave incorrect stackA in child\n", num == 2);
	pull_stack(parent->stackA, &num);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, ra operation gave incorrect stackA in parent\n", num == 1);
	free_state(parent);
	free_state(child);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&parent, stackA);
	rc = succeed_state(parent, &child, "pb");
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation failed\n", rc == 0);
	pull_stack(child->stackB, &num);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect stackB in child\n", num == 1);
	num = 5555;
	pull_stack(parent->stackB, &num);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect stackB in parent\n", num == 5555);
	free_state(parent);
	free_state(child);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&parent, stackA);
	succeed_state(parent, &child, "pb");
	oper = "hello";
	dequeue_queue(parent->trace, &oper);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect trace in parent\n", ft_strequ(oper, "hello"));
	dequeue_queue(child->trace, &oper);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect trace in child\n", ft_strequ(oper, "pb"));
	free_state(parent);
	free_state(child);
	free_stack(stackA);

	new_stack(&stackA);
	append_stack(stackA, 1);
	append_stack(stackA, 2);
	append_stack(stackA, 3);
	new_state(&parent, stackA);
	parent->g = 11;
	succeed_state(parent, &child, "pb");
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect g in parent\n", parent->g == 11);
	ASSERT("STATE: succeed_state with 1->2->3 in stackA, nothing in stackB, pb operation gave incorrect g in child\n", child->g == 12);
	free_state(parent);
	free_state(child);
	free_stack(stackA);

	return (0);
}

char		*state_test(void)
{
	RUN_TEST(heuristic_state_test);
	RUN_TEST(new_state_test);
	RUN_TEST(copy_state_test);
	RUN_TEST(is_goal_state_test);
	RUN_TEST(succeed_state_test);
	return (0);
}
