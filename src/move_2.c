/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:29:11 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 16:35:50 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	move_chank_to_a_top(t_stack_inf *s_inf, int pos, int u_num)
{
	int	i;

	i = 0;
	if (pos == B_BOTTOM)
	{
		if (u_num != ft_lstsize(s_inf->stack_b))
		{
			while (i++ < u_num)
				rrb(s_inf);
		}
		i = 0;
		while (i++ < u_num)
			pa(s_inf);
	}
	else if (pos == A_BOTTOM)
	{
		while (i++ < u_num)
			rra(s_inf);
	}
	else if (pos == B_TOP)
	{
		while (i++ < u_num)
			pa(s_inf);
	}
}
