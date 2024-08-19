/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:17:54 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/20 06:42:13 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	sa(t_stack_inf *stack_inf)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_a) < 2)
		return ;
	ft_lstswap_front(stack_inf->stack_a);
	describe_ope(stack_inf->ope_inf, SA);
}

void	pa(t_stack_inf *stack_inf)
{
	t_list	*tmp;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_b) == 0)
		return ;
	tmp = stack_inf->stack_b;
	stack_inf->stack_b = stack_inf->stack_b->next;
	tmp->next = stack_inf->stack_a;
	stack_inf->stack_a = tmp;
	describe_ope(stack_inf->ope_inf, PA);
}

void	ra(t_stack_inf *stack_inf)
{
	t_list	*tmp;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_a) < 2)
		return ;
	tmp = stack_inf->stack_a;
	stack_inf->stack_a = stack_inf->stack_a->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack_inf->stack_a, tmp);
	describe_ope(stack_inf->ope_inf, RA);
}

void	rra(t_stack_inf *stack_inf)
{
	t_list	*tmp;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_a) < 2)
		return ;
	tmp = ft_lstlast(stack_inf->stack_a);
	ft_lstadd_front(&stack_inf->stack_a, tmp);
	ft_lstdel_lastone(&stack_inf->stack_a);
	describe_ope(stack_inf->ope_inf, RRA);
}
