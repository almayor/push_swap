/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:45:29 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 12:14:23 by unite            ###   ########.fr       */
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
int heuristic_state(const t_state *state);

#endif
