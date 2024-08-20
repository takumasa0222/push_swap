/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/20 18:20:39 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	if (1 < unit_num && unit_num <= 3)
	{
		if (pos == A_BOTTOM)
			move_a(stack_inf, pos);
		short_sort(stack_inf);
	}
	else if (3 < unit_num && unit_num <= 5)
		mid_sort(stack_inf, A_BOTTOM);
	else
		throw_err(stack_inf, NULL, MEM_ALLOCATION_ERR);
}

void	short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (!s || !s->next)
		return ;
	else if (!s->next->next)
		sa(stack_inf);
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) < tp(s, 3))
	{
		sa(stack_inf);
		ra(stack_inf);
	}
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3), tp(s, 1) < tp(s, 3))
		sa(stack_inf);
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) > tp(s, 3))
		rra(stack_inf);
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3), tp(s, 1) > tp(s, 3))
		ra(stack_inf);
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) > tp(s, 3))
	{
		ra(stack_inf);
		sa(stack_inf);
	}
}

int	tp(t_list *stack, int i)
{

}