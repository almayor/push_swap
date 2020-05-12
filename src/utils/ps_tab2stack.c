/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:40:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 22:40:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ps_tab2stack(char **tab, t_stack *stack)
{
	while (*tab)
	{
		if (!ps_isnumeric_str(*tab))
			ps_exit("Error", 1);
		append_stack(stack, ft_atoi(*tab))
		tab += 1;
	}
	if (!isset_stack(stack))
		ps_exit("Error", 1);
}
