/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:04:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:36:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintfgnl.h"
# include "stack.h"
# include <errno.h>

void	advanced_sort(t_stack *sa, t_stack *sb);
void	simple_sort(t_stack *sa, t_stack *sb);
void	set_verbose(int code);
int		perform_operation(t_stack *sa, t_stack *sb, char *oper);

int		ps_atoi(const char *str, int *resp);
void	ps_exit(int code);
int		ps_index_stack(t_stack *stack);
int		ps_isnumeric_str(const char *str);
int		ps_tab2stack(char **tab, t_stack *stack);

#endif
