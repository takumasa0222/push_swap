/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:17:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/31 20:35:36 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	// int	i;
	(void)pos;
	// i = 0;
	// while (i++ < unit_num)
	// 	move_to_a_top(stack_inf, pos);
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
		// if (!stack)
		// 	throw_err();
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

//void	mid_sort(t_stack_inf *st_inf, int u_num)
//{
//	int	pb_i;
//	int	rra_i;

//	pb_i = 0;
//	rra_i = 0;
//	while (pb_i++ < u_num - 3)
//		pb(st_inf);
//	if (ft_lstsize(st_inf->stack_a == 3))
//		super_short_sort(st_inf);
//	else
//		short_sort(st_inf);
//	if (u_num == 5 && tp(st_inf->stack_b, 1) < tp(st_inf->stack_b, 2))
//		sb(st_inf);
//	while (tp(st_inf->stack_a, 1) < tp(st_inf->stack_b, 1) && rra_i++ < u_num)
//		rra(st_inf);
//	pa(st_inf);
//	pa(st_inf);
//}

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
//	//	throw_err(stack_inf, op_inf, MEM_ALLOC_ERR);
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

