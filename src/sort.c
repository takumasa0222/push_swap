/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 16:56:37 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	int	i;

	i = 0;
	while (i++ < unit_num)
		move_to_a_top(stack_inf, pos);
	if (unit_num == 2)
		sort_two(stack_inf);
	else if (ft_lstsize(stack_inf->stack_a) == 3)
		super_short_sort(stack_inf);
	else if (3 < ft_lstsize(stack_inf->stack_a))
		short_sort(stack_inf);
}

void	super_short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (!s || !s->next || !s->next->next)
		throw_err(stack_inf, NULL, NULL_ERR);
	if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) < tp(s, 3))
	{
		sa(stack_inf);
		ra(stack_inf);
	}
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3) && tp(s, 1) < tp(s, 3))
		sa(stack_inf);
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) > tp(s, 3))
		rra(stack_inf);
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) < tp(s, 3) && tp(s, 1) > tp(s, 3))
		ra(stack_inf);
	else if (tp(s, 1) > tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) > tp(s, 3))
	{
		ra(stack_inf);
		sa(stack_inf);
	}
}

int	tp(t_list *stack, int i)
{
	int	ret;
	int	j;

	ret = 0;
	j = 1;
	if (!stack)
		return (ret);
	while (j < i)
	{
		stack = stack->next;
		j++;
	}
	ret = *(int *)stack->content;
	return (ret);
}

void	sort_two(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (!s || !s->next)
		throw_err(stack_inf, NULL, NULL_ERR);
	if (tp(s, 2) < tp (s, 1))
		sa(stack_inf);
}

void	short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) < tp(s, 3))
	{
		ra(stack_inf);
		sa(stack_inf);
		rra(stack_inf);
	}
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3) && tp(s, 1) > tp(s, 3))
	{
		ra(stack_inf);
		sa(stack_inf);
		rra(stack_inf);
		sa(stack_inf);
	}
	else if (tp(s, 1) > tp(s, 2) && tp(s, 1) > tp(s, 3))
	{
		sa(stack_inf);
		short_sort(stack_inf);
	}
	else
		super_short_sort(stack_inf);
}
