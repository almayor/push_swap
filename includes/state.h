/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:45:29 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 11:44:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H

# define STATE_H

# include <stdlib.h>
# include "libft.h"
# include "stack.h"
# include "queue.h"
# include "operations.h"

typedef struct	s_state
{
	int		g;
	int		h;
	t_stack	*stackA;
	t_stack	*stackB;
	t_queue	*trace;
}				t_state;

int copy_state(const t_state *state1, t_state **state2);
int free_state(t_state *state);
int	is_goal_state(const t_state *state);
int	new_state(t_state **state, t_stack *stackA);
int succeed_state(const t_state *parent, t_state **child, char *oper);

/*
** heuristics
*/

int heuristic_state(const t_state *state);
int admissible_heuristic_state(const t_state *state);
int double_heuristic_state(const t_state *state);
int all_pairs_heuristic_state(const t_state *state);
int scaled_heuristic_state(const t_state *state);

#endif
