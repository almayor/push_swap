/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_search.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:39:58 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 08:31:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SEARCH_H

# define A_SEARCH_H

# include "state.h"
# include "heap.h"
# include "queue.h"
# include "stack.h"
# include "utils.h"
# include "operations.h"

int			A_search(t_stack *stackA, t_queue **trace);

#endif
