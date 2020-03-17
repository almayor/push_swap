/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:56:07 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 09:47:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H

# define TESTS_H

# include "A_search.h"
# include "graphics.h"
# include "heap.h"
# include "libft.h"
# include "operations.h"
# include "push_swap.h"
# include "queue.h"
# include "stack.h"
# include "state.h"
# include "utils.h"

/*
** http://www.jera.com/techinfo/jtns/jtn002.html
*/

# define ASSERT(message, test) do { tests_run++; if (!(test)) return message; } while (0)
# define RUN_TEST(test) do { char *message = test(); \
                                if (message) return message; } while (0)
extern int tests_run;


char	*heap_test(void);
char	*queue_test(void);
char	*stack_test(void);
char	*state_test(void);
char	*operations_test(void);
char	*is_numeric_str_test(void);
char	*ft_atoi2_test(void);
char	*A_search_test(void);

#endif
