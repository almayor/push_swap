/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:32:31 by unite             #+#    #+#             */
/*   Updated: 2020/03/18 09:38:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef	struct			s_link
{
	int					value;
	struct s_link		*next;
	struct s_link		*previous;
}						t_link;

typedef struct			s_stack
{
    size_t              size;
	struct s_link		*start;
	struct s_link		*end;
}						t_stack;

int	append_stack(t_stack *stack, int value);
int	free_stack(t_stack *stack);
int new_stack(t_stack *stack);
int	has_duplicates_stack(const t_stack *stack);
int	is_sorted_stack(const t_stack *stack);
int	print_stack(const t_stack *stack);
int	pull_stack(t_stack *stack, int *value);
int	push_stack(t_stack *stack, int value);
int	reverse_rotate_stack(t_stack *stack);
int	rotate_stack(t_stack *stack);
int	swap_stack(t_stack *stack);
int	min_stack(t_stack *stack, size_t length, int *min);
int	max_stack(t_stack *stack, size_t length, int *max);
int	avg_stack(t_stack *stack, size_t length, int *avg);

#endif
