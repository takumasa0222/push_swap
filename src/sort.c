/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/24 03:59:56 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	if (1 < unit_num && unit_num <= 3)
	{
		move_to_a_top(stack_inf, pos);
		if (unit_num == 2)
			sa(stack_inf);
		else if (unit_num == 3 && ft_lstsize(stack_inf->stack_a) == 3)
			super_short_sort(stack_inf);
		else
			short_sort(stack_inf);
	}
	else if (3 < unit_num && unit_num <= 5)
		mid_sort(stack_inf, A_BOTTOM);
	else
		throw_err(stack_inf, NULL, MEM_ALLOCATION_ERR);
}

void	super_short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (!s || !s->next || !s->next->next)
		throw_err(stack_inf, NULL, NULL_ERR);
	if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) < tp(s, 3))
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
	int	*ret;
	int	j;

	ret = 0;
	j = 1;
	if (!stack)
		return (ret);
	while (j < i)
	{
		if (!stack)
			throw_err();
		stack = stack->next;
		j++;
	}
	ret = (int *)stack->content;
	return (*ret);
}

void	mid_sort(t_stack_inf *stack_inf, int pos)
{
	
}

short_sort(t_stack_inf *stack_inf)
{
	t_list	*s;

	s = stack_inf->stack_a;
	if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) < tp(s, 3))
	{
		ra(stack_inf);
		sa(stack_inf);
		rra(stack_inf);
	}
	else if (tp(s, 1) < tp(s, 2) && tp(s, 2) > tp(s, 3), tp(s, 1) > tp(s, 3))
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

//int	main(void)
//{
//	t_ope_inf *op_inf;
//	t_stack_inf *stack_inf;
//	int a, b, c, d, e;
//	t_list	*temp_a, *temp_b;
//	//exit(0);

//	a = 1;
//	b = 3;
//	c = 5;
//	d = 7;
//	e = 9;
//	stack_inf = malloc(1 * sizeof(t_stack_inf));
//	op_inf = malloc(1 * sizeof(t_ope_inf));
//	//if (!stack_inf || !op_inf)
//	//	throw_err(stack_inf, op_inf, MEM_ALLOCATION_ERR);
//	op_inf->i = 0;
//	stack_inf->stack_a = ft_lstnew(&b);
//	stack_inf->stack_a->next = ft_lstnew(&e);
//	stack_inf->stack_a->next->next = ft_lstnew(&d);
//	//stack_inf->stack_a->next->next->next = ft_lstnew(&a);
//	stack_inf->stack_b = ft_lstnew(NULL);
//	short_sort(stack_inf);
//	temp_a = stack_inf->stack_a;
//	while (temp_a)
//	{
//		printf("value is %d\n",*((int*)temp_a->content));
//		temp_a = temp_a->next;
//	}
//	free(op_inf);
//	free(stack_inf);
//}

