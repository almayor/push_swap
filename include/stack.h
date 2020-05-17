/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:32:31 by unite             #+#    #+#             */
/*   Updated: 2020/05/17 02:24:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include <stdlib.h>
# include <errno.h>
# include "libftprintfgnl.h"

typedef	struct	s_link
{
	int				value;
	struct s_link	*next;
	struct s_link	*previous;
}				t_link;

typedef struct	s_stack
{
	int				size;
	struct s_link	*start;
	struct s_link	*end;
}				t_stack;

int				append_stack(t_stack *stack, int value);
int				avg_stack(const t_stack *stack);
void			free_stack(t_stack *stack);
int				get_stack(const t_stack *stack, int index);
int				isset_stack(const t_stack *stack);
int				issorted_stack(const t_stack *stack);
int				max_stack(const t_stack *stack);
int				min_stack(const t_stack *stack);
void			new_stack(t_stack *stack);
void			print_stack(const t_stack *stack);
int				pull_stack(t_stack *stack);
int				push_stack(t_stack *stack, int value);
void			reverse_rotate_stack(t_stack *stack);
void			rotate_stack(t_stack *stack);
int				search_stack(const t_stack *stack, int num, int comp,
							int order);
void			swap_stack(t_stack *stack);

#endif
