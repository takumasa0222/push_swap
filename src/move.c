/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 02:30:52 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/24 04:35:03 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	move_to_a_top(t_stack_inf *stack_inf, int pos)
{
	if (pos == A_BOTTOM)
		rra(stack_inf);
	else if (pos == B_TOP)
		pa(stack_inf);
	else if (pos == B_BOTTOM)
	{
		rrb(stack_inf);
		pa(stack_inf);
	}
}

void	move_to_a_bottom(t_stack_inf *stack_inf, int pos)
{
	if (pos == A_TOP)
		ra(stack_inf);
	else if (pos == B_TOP)
	{
		pa(stack_inf);
		ra(stack_inf);
	}
	else if (pos == B_BOTTOM)
	{
		rrb(stack_inf);
		pa(stack_inf);
		ra(stack_inf);
	}
}

void	move_to_b_top(t_stack_inf *stack_inf, int pos)
{
	if (pos == A_BOTTOM)
	{
		rra(stack_inf);
		pb(stack_inf);
	}
	else if (pos == A_TOP)
		pb(stack_inf);
	else if (pos == B_BOTTOM)
		rrb(stack_inf);
}

void	move_to_b_bottom(t_stack_inf *stack_inf, int pos)
{
	if (pos == A_TOP)
	{
		pb(stack_inf);
		rb(stack_inf);
	}
	else if (pos == B_TOP)
	{
		rb(stack_inf);
	}
	else if (pos == A_BOTTOM)
	{
		rra(stack_inf);
		pb(stack_inf);
		rb(stack_inf);
	}
}

void	move_back(t_stack_inf *stack_inf, int pos, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (pos == B_TOP || pos == B_BOTTOM)
			pb(stack_inf);
		else if (pos == A_BOTTOM)
			ra(stack_inf);
		i++;
	}
}
