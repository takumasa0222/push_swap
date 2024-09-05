/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:16:26 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/06 01:01:31 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	is_partial_sorted(t_stack_inf *s_i, int pos, int unum)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (i < unum - 3)
	{
		if (unum - i - 1 <= 0)
			break ;
		tmp = take_x_elem(s_i, pos, unum - 1 - i);
		j = 0;
		while (j <= unum - 1 - i)
		{
			if (pos % 2 && tmp < take_x_elem(s_i, pos, unum - i - 1 - j))
				return (NOT_SORTED);
			if (!(pos % 2) && tmp > take_x_elem(s_i, pos, unum - i - 1 - j))
				return (NOT_SORTED);
			j++;
		}
		i++;
	}
	return (SORTED);
}

void	partial_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	int	i;

	i = 0;
	if (pos == A_TOP)
		basic_sort(stack_inf, pos, 3);
	else if (pos == A_BOTTOM)
	{
		basic_sort(stack_inf, pos, 3);
		while (i++ < unit_num - 3)
			move_to_a_top(stack_inf, pos);
	}
	else if (pos == B_TOP)
	{
		basic_sort(stack_inf, pos, 3);
		while (i++ < unit_num - 3)
			move_to_a_top(stack_inf, pos);
	}
	else if (pos == B_BOTTOM)
	{
		while (i++ < 3)
			move_to_b_top(stack_inf, pos);
		b_short_sort(stack_inf);
		i = 0;
		while (i++ < unit_num - 3)
			move_to_b_top(stack_inf, pos);
		i = 0;
		while (i++ < unit_num)
			move_to_a_top(stack_inf, B_TOP);
	}
}

void	b_short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_b;
	if ((tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3) && tp(s, 1) > tp(s, 3)) \
	|| (tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3) && tp(s, 1) < tp(s, 3)))
	{
		rb(stack_inf);
		sb(stack_inf);
		rrb(stack_inf);
		b_short_sort(stack_inf);
	}
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) > tp(s, 3))
		sb(stack_inf);
	else if ((tp(s, 1) < tp(s, 2) && tp(s, 2) < tp(s, 3) && tp(s, 1) < tp(s, 3)) \
	|| (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) < tp(s, 3)))
	{
		sb(stack_inf);
		b_short_sort(stack_inf);
	}
}
